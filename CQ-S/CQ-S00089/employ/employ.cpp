#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define close return cout << 0,0
using namespace std;
void freopen_()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
const int S=998244353; 
int n,m,s[510],c[510],xa=1,vis[510],visp[510],mp[55],vis_[55];
char ss[510];
int ans=0;
int maxm,misr=0,I=0;
void f1(int vs)
{
	if(vs>n)
	{
		int missb=0,sucp=n;
		for(int i=1;i<=n;i++)
		{
			if(missb>=mp[i]||s[i]==0){
				missb++,sucp--;
				if(sucp<m) return;
			}
		}
		ans++;
		ans%=S;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis_[i])
		{
			vis_[i]=1;
			mp[vs]=c[i];
			f1(vs+1);
			vis_[i]=0;
		}
	}
}
void f2(int vs,int missb,int sucp,int rc)
{
	if(vs>n)
	{
		ans++;
		ans%=S;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis_[i])
		{
			vis_[i]=1;
			vis[c[i]]--;
			if(missb>=c[i]||s[vs]==0)
			{
//				cout << missb << " " << c[i] << " " << s[vs] << endl;
				if(sucp-1<m||rc-vis[missb]-1<m){
					vis_[i]=0;
					vis[c[i]]++;
					continue;
				}
				f2(vs+1,missb+1,sucp-1,rc-vis[missb]-1);
			}
			else f2(vs+1,missb,sucp,rc);
			vis_[i]=0;
			vis[c[i]]++;
		}
	}
}
signed main()
{
	freopen_();
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> ss[i];
		s[i]=int(ss[i]-'0');
		if(s[i]==0) xa=0;
		
	}
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		vis[c[i]]++;
	}
	if(vis[0]==n) goto genshin;
	if(m==1)
	{
		ans=1;
		for(int i=1;i<=n-vis[0]-1;i++)
			ans=(ans*2)%S;
		cout << ans;
		return 0;
	}
	maxm=n-m-vis[0],misr=0,I=0;
	if(maxm<0) goto genshin;
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
		{
			I=i;
			break;
		}
		misr++;
		maxm-=vis[misr];
		if(maxm<0) goto genshin;
	}
	if(n<=10)
	{
		f1(1);
		return cout << ans,0;
	}
	if(n<=18)
	{
		int xxx=n-vis[0];
		vis[0]=0;
		f2(1,0,n,xxx);
		return cout << ans,0;
	}
	return 0;
	genshin:
		close;
}
/*
please follow flysfy_LJX in luogu,flysfy_LJX will follow you,too!
//although it is my last OI compete
10 10
1111111111
1 2 3 4 5 4 3 1 2 3
512

5 3
11111
1 2 3 4 4

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

