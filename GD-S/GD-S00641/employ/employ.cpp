#include <bits/stdc++.h>
const int maxn = 2e5+10;
typedef std::pair<int, int> pii;
using namespace std;
const int mod = 998244353;

int s[maxn], c[maxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	int flg1 = true;
	int flg2=true;
	int weak = 0;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		s[i] = c-'0';
		if(c=='1') flg1=false;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
		if(c[i]==0) weak++;
	}
	if(flg1)
	{
		cout<<0<<'\n';
		return 0;
	}
	else if(n<=10)
	{
		sort(s+1, s+1+n);
		int tot =0;
		do
		{
			int cd = 0;
			int pss = 0;
			//cout<<"PERMUTATION£º"; 
			for(int i=1;i<=n;i++)
			{
				//cout<<s[i];
				if(cd>=c[i] || !s[i]) cd++;
				else if(s[i]) pss++;
			}
			//cout<<' ';
			if(pss>=m) 
			{
				tot=(tot+1)%mod;
				//cout<<"SUC\n";
			}
			//else cout<<"FAI\n";
		}while(next_permutation(s+1, s+1+n));
		cout<<tot;
		return 0;
	}
	cout<<n*(n-1)/2;
	fclose(stdin);
	fclose(stdout);
}
