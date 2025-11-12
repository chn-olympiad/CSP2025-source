#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+5,M=5e6+5,mod=1e9+7;
int n,q,s,p=131,hx[M],hy[M],pown[M];
string x,y;
struct X{
	int l,cd;//lx：x.size和y.size,cd：第一个不同的位置
	int hsx,hsy;//x和y的哈希值 
}a[N];
int qjhsx(int l,int r){
	if(l>r)return 0;
	return (hx[r]-hx[l-1]*pown[r-l+1]%mod+mod)%mod;
}
int qjhsy(int l,int r){
	if(l>r)return 0;
	return (hy[r]-hy[l-1]*pown[r-l+1]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	pown[0]=1;
	for(int i=1;i<M;i++)pown[i]=pown[i-1]*p%mod;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[i].l=x.size();
		x=" "+x,y=" "+y;
		for(int j=1;j<=a[i].l;j++)
		{
			hx[j]=hx[j-1]*p%mod+(x[j]-'0'),hx[j]%=mod;
			hy[j]=hy[j-1]*p%mod+(y[j]-'0'),hy[j]%=mod;
		}
		a[i].hsx=hx[a[i].l],a[i].hsy=hy[a[i].l];
		int l=1,r=a[i].l;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if(hx[mid]==hy[mid])l=mid;
			else r=mid;
		}
		if(hx[r-1]!=hy[r-1])r--;
		a[i].cd=r;
	}
	while(q--)
	{
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}
		int dqcd=0,ret=0,lxy=x.size();//dqcd: 当前x,y第一个不同的位置，ret：方案,lxy: size
		x=" "+x,y=" "+y;
		for(int i=1;i<=lxy;i++)
		{
			hx[i]=hx[i-1]*p%mod+(x[i]-'0'),hx[i]%=mod;
			hy[i]=hy[i-1]*p%mod+(y[i]-'0'),hy[i]%=mod;
		}
		int l=1,r=lxy;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if(hx[mid]==hy[mid])l=mid;
			else r=mid;	
		} 
		if(hx[r-1]!=hy[r-1])r--;
		dqcd=r;
		for(int i=1;i<=n;i++)
		{
			int cd=a[i].cd,l=a[i].l,hsx=a[i].hsx,hsy=a[i].hsy;
			if(qjhsx(l-cd+dqcd+1,lxy)==qjhsy(l-cd+dqcd+1,lxy)&&qjhsx(dqcd-cd+1,l-cd+dqcd)==hsx&&qjhsy(dqcd-cd+1,l-cd+dqcd)==hsy)ret++;
		}
		cout<<ret<<endl;
	}
	return 0;
}

