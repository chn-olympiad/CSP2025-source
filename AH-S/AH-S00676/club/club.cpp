#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int n;
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].x;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
