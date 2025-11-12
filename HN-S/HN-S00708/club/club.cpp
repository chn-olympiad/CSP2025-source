#include<bits/stdc++.h>
using namespace std;
int n,k,t;
struct ti{
	int x,y,z;
}a[100005];
int cmp(ti a,ti b){
	return max(a.x,max(a.y,a.z))<max(b.x,max(b.y,b.z));
}
int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a,a+n,cmp);k=0;
		for(int i=0;i<n;i++)k+=max(a[i].x,max(a[i].y,a[i].z));
		cout<<k<<endl;
	}
	return 0;
}
