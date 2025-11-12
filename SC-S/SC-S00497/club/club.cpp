#include<bits/stdc++.h>
using namespace std;
namespace A{
	int t,n,b,flag1,flag2,c1,c2,c3,ans;
	struct node{
		int x,y,z;
	}a[100010];
	bool cmp1(node x,node y){
		return x.x>y.x;
	}
	bool cmp2(node x,node y){
		return x.y>y.y;
	}
	bool cmp3(node x,node y){
		return x.z>y.z;
	}
	int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin>>t;
		for(int k=1;k<=t;k++){
			ans=0;
			flag1=0;
			flag2=0;
			c1=0;
			c2=0;
			c3=0;
			cin>>n;
			b=n/2;
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
			}
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(c1<b&&a[i].x>0){
					ans+=a[i].x;
					//cout<<ans<<" ";
					a[i].y=-1;
					a[i].z=-1;
				}
				else{
					continue;
				}
			}
			cout<<ans<<"\n";
			/*
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(c2<b&&a[i].y>0){
					ans+=a[i].y;
					//cout<<ans<<" ";
					a[i].x=-1;
					a[i].z=-1;
				}
				else{
					continue;
				}
			}
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n;i++){
				if(c3<b&&a[i].z>0){
					ans+=a[i].z;
					//cout<<ans<<" ";
					a[i].y=-1;
					a[i].x=-1;
				}
				else{
					continue;
				}
			}
			cout<<ans<<"\n";
		*/
		}
		return 0;
	}
}
int main(){
	return A::main();
}