#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define N 200010
#define For(i,a,b) for(register int i=a;i<=b;++i)
#define Rof(i,a,b) for(register int i=a;i>=b;--i)
#define ls x<<1
#define rs x<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define pb push_back
#define mk make_pair
#define pque priority_queue
#define pii pair<ll,ll>
#define fi first
#define se second

using namespace std;
ll a[N][3],tim[3],b[N];
int T,n;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void sol(){
	n=read();
	ll ans=0;
	tim[0]=tim[1]=tim[2]=0;
	For(i,1,n){
		int mx=0;
		For(j,0,2){
			a[i][j]=read();
		}
		For(j,0,2) if(a[i][j]>a[i][mx]) mx=j;
		ans+=a[i][mx];
		tim[mx]++;
		b[i]=mx;
	}
	int mx=0;
	For(i,0,2) if(tim[i]>tim[mx]) mx=i;
	pque<ll >q;
	For(i,1,n){
		if(b[i]==mx){
			ll mn=1e18;
			For(j,0,2) if(j!=mx) mn=min(mn,a[i][mx]-a[i][j]);
			q.push(-mn);
		}
	}
	while(tim[mx]>n/2){
		ans+=q.top();
		q.pop();
		tim[mx]--;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) sol();
	return 0;
}
