#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,ans,cnt1,cnt2,cnt3;
struct q{
	ll a[4],b,c;
}p[100010];
ll ma(ll a,ll b){
	return a>b?a:b;
}
bool cmp(q x,q y){
	return x.c<y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>p[j].a[1]>>p[j].a[2]>>p[j].a[3];
			if(ma(ma(p[j].a[1],p[j].a[2]),p[j].a[3])==p[j].a[1])cnt1++,ans+=p[j].a[1],p[j].b=1;
			else if(ma(ma(p[j].a[1],p[j].a[2]),p[j].a[3])==p[j].a[2])cnt2++,ans+=p[j].a[2],p[j].b=2;
			else cnt3++,ans+=p[j].a[3],p[j].b=3;			
			sort(p[j].a+1,p[j].a+4);
			p[j].c=p[j].a[3]-p[j].a[2];	
		}
		sort(p+1,p+n+1,cmp);
		int z=1;
		if(cnt1>n/2){
			while(cnt1>n/2){
				if(p[z].b==1)cnt1--,ans-=p[z].c;
				z++;
			}
		}else if(cnt2>n/2){
			while(cnt1>n/2){
				if(p[z].b==2)cnt2--,ans-=p[z].c;
				z++;
			}
		}else{
			while(cnt3>n/2){
				if(p[z].b==3)cnt3--,ans-=p[z].c;
				z++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
