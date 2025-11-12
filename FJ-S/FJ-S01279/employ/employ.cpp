#include <iostream>
using namespace std;
const int MOD=998244353;
int n,m,v[505],on,ze,ans,w;
string s;
bool t[505];
int per(int s)
{
	int a=1;
	while(s)
	{
		a*=s;
		a%=MOD;
		s--;
	}
	return a;
}
void work(int h,int k,int p)
{
	if(k==m)
	{
		ans+=per(n-h+1);
		ans%=MOD; 
		return ;
	}
	if(h>n) return ;
	for (int i=1;i<=n;i++){
		if(t[i]==0)
		{
			if(s[h-1]=='0'||v[i]<=p)
			{
				t[i]=1;
				work(h+1,k,p+1);
				t[i]=0;
			}
			else
			{
				t[i]=1;
				work(h+1,k+1,p);
				t[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if (s[i]=='0') ze++;
		else on++;
	}
	if (n==on)
	{
		ans=per(n);
		for (int i=1;i<=n;i++)
		{
			if (v[i]==0)
			{
				ans=0;
				break;
			}
		}
		if (ans!=0){
			cout<<ans;
			return 0;
		}
	}
	if (on<m)
	{
		cout<<0;
		return 0;
	}
	work(1,0,0);
	cout<<ans;
	return 0;
}
