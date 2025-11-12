#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll t,n,a[N],b[N],c[N];
ll cnt1,cnt2,cnt3,m,col[N],ans;
ll d[N],len,qwq;
void work(){
	cnt1=cnt2=cnt3=ans=len=0; m=n/2;
	for(ll i=1;i<=n;i++){
			 if(a[i]>=max(b[i],c[i])) col[i]=1,ans+=a[i],cnt1++;
		else if(b[i]>=max(a[i],c[i])) col[i]=2,ans+=b[i],cnt2++;
		else if(c[i]>=max(a[i],b[i])) col[i]=3,ans+=c[i],cnt3++;
		else{
//			puts("WTF");
		}}
	if(cnt1>m){
		for(ll i=1;i<=n;i++)
			if(col[i]==1) d[++len]=min(a[i]-b[i],a[i]-c[i]);
	}
	if(cnt2>m){
		for(ll i=1;i<=n;i++)
			if(col[i]==2) d[++len]=min(b[i]-a[i],b[i]-c[i]);
	}
	if(cnt3>m){
		for(ll i=1;i<=n;i++)
			if(col[i]==3) d[++len]=min(c[i]-a[i],c[i]-b[i]);
	}
	qwq=max(max(cnt1,cnt2),cnt3)-m;
	if(qwq>0){
		sort(d+1,d+len+1);
		for(ll i=1;i<=qwq;i++) ans-=d[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

//	freopen("club1.in","r",stdin);
//	freopen("club5.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		work();
		cout<<ans<<'\n';
	}
	fflush(stdout);
	return 0;}






















