#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
ll read(){
	ll ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
const ll N=2e5,L=5e6;
ll n,q,ans;
string o[N+5][2],t1,t2;
ll sz[N+5];
void init(){
	ans=0;
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(ll i=1;i<=n;i++)
	{
		cin>>o[i][0]>>o[i][1];
		sz[i]=o[i][0].size();
	}
	while(q--)
	{
		cin>>t1>>t2;
		ll szt=t1.size();
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=0;j<=szt-sz[i];j++)
			{
				ll k=0;
				while(t1[j+k]==o[i][0][k]&&k<sz[i])k++;
				if(k==sz[i])
				{
//					cout<<" "<<i<<" "<<j<<" "<<k<<endl;
					ll f=1;
					for(ll l=0;l<j;l++)
					{
//						cout<<l<<" "<<t2[l]<<t1[l]<<endl;
						if(t2[l]!=t1[l])
						{
							f=0;
							break;
						}
					}
					for(ll l=j;l<j+k;l++)
					{
						if(t2[l]!=o[i][1][l-j])
						{
							f=0;
							break;
						}
					}
					for(ll l=j+k;l<szt;l++)
					{
						if(t2[l]!=t1[l])
						{
							f=0;
							break;
						}
					}
					ans+=f;
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
