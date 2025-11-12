#include <bits/stdc++.h>
using namespace std;

ifstream fin("club.in",ios_base::in);
ofstream fout("club.out",ios_base::out);

#define maxN 100005

int n;
int a[maxN],b[maxN],c[maxN];

struct node
{
	long long vals,valc;
	bool operator<(const node A) const
	{
		return valc < A.valc;
	}
};
vector<node> pa,pb,pc;
long long ans;

int main()
{
	ios::sync_with_stdio(0);
	fin.tie(0);
	fout.tie(0);
	int t;
	fin >> t;
	while(t--)
	{
		pa.clear();
		pb.clear();
		pc.clear();
		ans = 0;
		fin >> n;
		for(int i = 1; i <= n; i++)
		{
			fin >> a[i] >> b[i] >> c[i];
			if(a[i] >= b[i] && a[i] >= c[i])
				pa.push_back({a[i],a[i] - max(b[i],c[i])}),ans += a[i];
			else if(b[i] >= c[i] && b[i] >= a[i])
				pb.push_back({b[i],b[i] - max(a[i],c[i])}),ans += b[i];
			else if(c[i] >= a[i] && c[i] >= b[i])
				pc.push_back({c[i],c[i] - max(a[i],b[i])}),ans += c[i];
		}
		if(pa.size() > n/2)
		{
			sort(pa.begin(),pa.end());
			for(int i = 0; i < pa.size() - n/2; i++)
				ans -= pa[i].valc;		
		}
		else if(pb.size() > n/2)
		{
			sort(pb.begin(),pb.end());
			for(int i = 0; i < pb.size() - n/2; i++)
				ans -= pb[i].valc;
		}
		else if(pc.size() > n/2)
		{
			sort(pc.begin(),pc.end());
			for(int i = 0; i < pc.size() - n/2; i++)
				ans -= pc[i].valc;
		}
		fout << ans << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}
