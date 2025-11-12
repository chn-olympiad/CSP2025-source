#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z;
}a[1000008];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].x;
		}
		cout<<ans<<endl;
	}
	
}
