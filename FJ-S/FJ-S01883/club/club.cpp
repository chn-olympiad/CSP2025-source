#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
const int N=1e5+5;
int n;
ll a[N][5];
int ps[N];
ll b[N];
void solve(){
	n=read();
	int c[5]; c[1]=c[2]=c[3]=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll mx=0;
		for(int j=1;j<=3;j++){
			a[i][j]=read();
			mx=max(mx,a[i][j]);
		}
		ans=ans+mx;
		for(int j=1;j<=3;j++){
			if(a[i][j]==mx){
				ps[i]=j; c[j]++; break;
			}
		}
	}
	int t=max(c[1],max(c[2],c[3]));
	if(t<=n/2){
		printf("%lld\n",ans); return;
	}
	if(t==c[1]) ;
	else if(t==c[2]){
		for(int i=1;i<=n;i++){
			swap(a[i][1],a[i][2]);
			if(ps[i]==1) ps[i]=2;
			else if(ps[i]==2) ps[i]=1;
		}
		swap(c[1],c[2]);
	}
	else{
		for(int i=1;i<=n;i++){
			swap(a[i][1],a[i][3]);
			if(ps[i]==1) ps[i]=3;
			else if(ps[i]==3) ps[i]=1;
		}
		swap(c[1],c[3]);
	}
	int lb=0;
	for(int i=1;i<=n;i++){
		if(ps[i]==1) b[++lb]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
	}
	sort(b+1,b+1+lb); reverse(b+1,b+1+lb);
	for(int i=1;i<=t-n/2;i++) ans=ans+b[i];
	printf("%lld\n",ans);
}
int main(){
//	system("fc club5.ans club.out"); return 0;
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
