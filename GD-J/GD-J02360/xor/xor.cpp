#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 5e5 + 42;

struct qujian
{
	int s;
	int e;	
};

bool cmp(qujian a,qujian b)
{
	return a.e < b.e;	
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k;
	
	vector<qujian> ij;
	
	cin>>n>>k;	
	int a[MAXN];
	for(int i = 0;i < n;i++) cin>>a[i];
	
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		int tans = 0;
		int curr = 0;
		int leng = 0;
		for(int j = i;j < n;j++)
		{
			curr ^= a[j];
			leng++;
			if(curr == k && leng >= 1)
			{ 
				curr = 0;
				leng = 0;
				ij.push_back(qujian{i,j});
			}
		}
	}
	int ijsize = ij.size();
	sort(ij.begin(),ij.end(),cmp);
	int mans = 0;
	int lat = -1;
	for(int i = 0;i < ijsize;i++)
	{
		if(lat < ij[i].s)
		{
			mans++;
			lat = ij[i].e;
		}
	}
	
	cout<<mans<<endl;
	return 0;
}
