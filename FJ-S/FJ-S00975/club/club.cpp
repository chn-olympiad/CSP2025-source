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
const ll N=1e5,Inf=1e18+5;
ll T,n,ans,o[N+5][4],clb[4];
struct New{
	ll dis,num;
}nw[N+5];
void init(){
	ans=0;
	clb[0]=clb[1]=clb[2]=clb[3]=0;
	return;
}
ll mxnum(ll x){
	if(o[x][0]==o[x][1])return 1;
	if(o[x][0]==o[x][2])return 2;
	return 3;
}
ll mxclbnum(){
	if(clb[0]==clb[1])return 1;
	if(clb[0]==clb[2])return 2;
	return 3;
}
ll cntnw(ll x){
	ll d1=o[x][0]-o[x][1];
	if(d1==0)d1=Inf;
	ll d2=o[x][0]-o[x][2];
	if(d2==0)d2=Inf;
	ll d3=o[x][0]-o[x][3];
	if(d3==0)d3=Inf;
	return min(d1,min(d2,d3));
}
bool cmp(New a,New b){
	return a.dis<b.dis;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		init();
		n=read();
		for(ll i=1;i<=n;i++)
		{
			o[i][1]=read();
			o[i][2]=read();
			o[i][3]=read();
			o[i][0]=max(o[i][1],max(o[i][2],o[i][3]));
			nw[i].dis=cntnw(i),nw[i].num=i;
			clb[mxnum(i)]++;
			ans+=o[i][0];
		}
		clb[0]=max(clb[1],max(clb[2],clb[3]));
		ll mxclb=mxclbnum();
		sort(nw+1,nw+1+n,cmp);
//		for(ll i=1;i<=n;i++)
//		{
//			cout<<nw[i].num<<" "<<nw[i].dis<<endl;
//		}
//		cout<<endl;
		ll i=1;
		while(clb[mxclb]>n/2)
		{
			while(mxnum(nw[i].num)!=mxclb)i++;
//			cout<<nw[i].num<<" "<<nw[i].dis<<endl;
			ans-=nw[i].dis;
			clb[mxclb]--;
			i++;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
