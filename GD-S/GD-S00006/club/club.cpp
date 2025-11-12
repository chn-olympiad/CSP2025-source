#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+10;
ll T,num[13],n,ans,f[N][13];
struct node{
	ll x,y,z,cha,ma1,ma2,ma3,bh;
}a[N];
bool cmp(node x,node y){
	if(x.cha!=y.cha) return x.cha>y.cha;
	else return x.ma1>y.ma1; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			f[i][1]=a[i].x;f[i][2]=a[i].y;f[i][3]=a[i].z;
			ll maxx=-0x3f3f3f3f,maxxi=0,ma2=-0x3f3f3f3f,ma2i=0;
			if(a[i].x>maxx){
				maxx=a[i].x;
				maxxi=1;
			}
			if(a[i].y>maxx){
				maxx=a[i].y;
				maxxi=2;
			}
			if(a[i].z>maxx){
				maxx=a[i].z;
				maxxi=3;
			}
			if(a[i].x>ma2&&maxxi!=1){
				ma2=a[i].x;
				ma2i=1;
			}
			if(a[i].y>ma2&&maxxi!=2){
				ma2=a[i].y;
				ma2i=2;
			}
			if(a[i].z>ma2&&maxxi!=3){
				ma2=a[i].z;
				ma2i=3;
			}
			a[i].ma1=maxxi;
			a[i].ma2=ma2i;
			a[i].ma3=6-maxxi-ma2i; 
			a[i].cha=f[i][a[i].ma1]-f[i][a[i].ma2];
			a[i].bh=i;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(num[a[i].ma1]<n/2){
				num[a[i].ma1]++;
				ans+=f[a[i].bh][a[i].ma1];
			}
			else if(num[a[i].ma2]<n/2){
				num[a[i].ma2]++;
				ans+=f[a[i].bh][a[i].ma2];
			}
			else{
				num[a[i].ma3]++;
				ans+=f[a[i].bh][a[i].ma3];
			}
		}
		cout<<ans<<"\n";
		ans=0;
		num[1]=num[2]=num[3]=0;
	}
	return 0; 
} 
