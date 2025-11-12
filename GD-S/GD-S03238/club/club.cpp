#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=1e5+5;
LL ans;
int n,max1,max2,al,bl,cl,a[N],b[N],c[N];
void solve(){
	cin>>n,ans=al=bl=cl=0;
	for(rint i=1,x,y,z;i<=n;++i){
		cin>>x>>y>>z;
		max1=max({x,y,z});
		if(max1==x) max2=max(y,z),a[++al]=max1-max2;
		else if(max1==y) max2=max(x,z),b[++bl]=max1-max2;
		else max2=max(x,y),c[++cl]=max1-max2;
		ans+=max1;
	}
	if(al>n/2) sort(a+1,a+al+1);
	if(bl>n/2) sort(b+1,b+bl+1);
	if(cl>n/2) sort(c+1,c+cl+1);
	for(rint i=1;i<=n;++i){
		if(al>=n/2+i) ans-=a[i];
		else if(bl>=n/2+i) ans-=b[i];
		else if(cl>=n/2+i) ans-=c[i];
		else break;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
