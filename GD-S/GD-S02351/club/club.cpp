#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
bool px1(node a1,node a2){
	return a1.x>a2.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long ans=0;
		for(int j=1;j<=n;j++)cin>>a[j].x>>a[j].y>>a[j].z;
		sort(a+1,a+n+1,px1);
		for(int j=1;j<=n/2;j++){
			ans+=a[j].x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
