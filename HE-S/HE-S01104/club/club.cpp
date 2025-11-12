#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct node{
	int x,y,z; 
}a[100005];
int abc(node b){
	if(b.x<=b.y&&b.y<=b.z){
		return b.z;
	}
	if(b.x>=b.y&&b.x>=b.z){
		return b.x;
	}
	if(b.x<=b.z&&b.y>=b.z){
		return b.y;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			ans+=abc(a[i]);
			cout<<ans<<endl;
		}
	}
} 
