#include<bits/stdc++.h>
using namespace std;
long long n,t,ans,o;
struct node{
	long long x,y,z;
	long long mxy,myz,mxz;
}a[100005];
bool cmp(node b,node c){
	return b.x>c.x;
}
bool cmp1(node b,node c){
	return b.y>c.y;
}
bool cmp2(node b,node c){
	return b.z>c.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		o=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		} 
		if(n==1){
			cout<<max(a[1].x,max(a[1].y,a[1].z));
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=o;i++){
			ans+=a[i].x;
			a[i].y=-1;
			a[i].z=-1;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=(o+1)%2;i++){
			ans+=a[i].y;
			a[i].z=-1;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=(o-1)%2;i++){
			ans+=a[i].z;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 