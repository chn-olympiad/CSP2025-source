#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+20;
int n;
struct P{
	int a,b,c;	
} pers[N],a[N],b[N],c[N]; 
bool acmp(P x,P y){
	return (x.a-max(x.b,x.c))>(y.a-max(y.b,y.c));
}
bool bbcmp(P x,P y){
	return (x.b-max(x.a,x.c))>(y.b-max(y.a,y.c));
}
bool ccmp(P x,P y){
	return (x.c-max(x.b,x.a))>(y.c-max(y.b,y.a));
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pers[i].a>>pers[i].b>>pers[i].c;
		a[i].a=b[i].a=c[i].a=pers[i].a;
		a[i].b=b[i].b=c[i].b=pers[i].b;
		a[i].c=b[i].c=c[i].c=pers[i].c;
	}
	sort(a+1,a+n+1,acmp);
	sort(b+1,b+n+1,bbcmp);
	sort(c+1,c+n+1,ccmp);
	int ans=0;
	int sum=0;
	int ac=0,bc=0,cc=0;
	for(int i=1;i<=n;i++){
		if(i>=1 && i<=n/2 && c[i].c-max(c[i].a,c[i].a)>0) sum+=c[i].c;
		else if(c[i].a>=c[i].b && ac<n/2){
			sum+=c[i].a;
			ac++;
		}
		else if(c[i].a<c[i].b && bc<n/2){
			sum+=c[i].b;
			bc++;
		}
	}
	ans=max(ans,sum);
	//cout<<sum<<endl;
	ac=0,bc=0,cc=0;
	sum=0;
	for(int i=1;i<=n;i++){
		if(i>=1 && i<=n/2 && a[i].a-max(a[i].b,a[i].c)>0) sum+=a[i].a;
		else if(a[i].b>=a[i].c && bc<n/2){
			sum+=a[i].b;
			bc++;
		}
		else if(a[i].b<a[i].c && cc<n/2){
			sum+=a[i].c;
			cc++;
		}
	}
	ans=max(ans,sum);
	//cout<<sum<<endl;
	sum=0;
	ac=0,cc=0,bc=0;
	for(int i=1;i<=n;i++){
		if(i>=1 && i<=n/2 && b[i].b-max(b[i].a,b[i].c)>0) sum+=b[i].b;
		else if(b[i].a>=b[i].c && ac<n/2){
			sum+=b[i].a;
			ac++;
		}
		else if(b[i].a<b[i].c && cc<n/2){
			sum+=b[i].c;
			cc++;
		}
		//cout<<b[i].b-max(b[i].a,b[i].c)<<endl;
	}
	ans=max(ans,sum);
	//cout<<sum<<endl;
	cout<<ans<<endl;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
