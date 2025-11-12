#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+2,mod=131,MOD=1e9+7;
struct node{
	int h1,h2,siz;
}a[N];
int n,q,pows[N],sum1[N],sum2[N],ans;
string s1,s2;
void H(int i)
{
	for(int j=0;j<s1.size();++j)a[i].h1=(a[i].h1*mod%MOD+s1[j])%MOD;
	for(int j=0;j<s2.size();++j)a[i].h2=(a[i].h2*mod%MOD+s2[j])%MOD;
}
bool cmp(node a,node b)
{
	return a.siz<b.siz;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	pows[0]=1;
	for(int i=1;i<N;++i)pows[i]=pows[i-1]*mod%MOD;
	for(int i=1;i<=n;++i)
	{
		cin>>s1>>s2;
		a[i].siz=s1.size();
		H(i);
	}
	sort(a+1,a+1+n,cmp);
	int l,r;
	while(q--)
	{
		cin>>s1>>s2;
		ans=0;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		for(l=0;l<s1.size()&&s1[l]==s2[l];++l);
		for(r=s1.size()-1;~r&&s1[r]==s2[r];--r);
		for(int i=0,j,x,y;i<s1.size();++i)
		{
			if(!i)sum1[i]=s1[i],sum2[i]=s2[i];
			else sum1[i]=(sum1[i-1]*mod+s1[i])%MOD,sum2[i]=(sum2[i-1]*mod+s2[i])%MOD;
			if(i>=r)
			{
				for(j=1;j<=n&&i-a[j].siz+1>=0;++j)
				{
					if(i-a[j].siz+1>l)continue;
					if(i<a[j].siz)x=sum1[i],y=sum2[i];
					else x=(sum1[i]-(sum1[i-a[j].siz]*pows[a[j].siz]%MOD)+MOD)%MOD,y=(sum2[i]-(sum2[i-a[j].siz]*pows[a[j].siz]%MOD)+MOD)%MOD;
					if(x==a[j].h1&&y==a[j].h2)++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
