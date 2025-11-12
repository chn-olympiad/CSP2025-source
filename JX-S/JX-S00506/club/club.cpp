#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
}a[100005];
bool cmp(Node x,Node y){
	return x.x>y.x;
}
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		bool f=1,f1=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(!(a[i].y==a[i].z&&a[i].y==a[i-1].y&&a[i].z==a[i-1].z&&a[i].y==0))f=0;
			if(!(a[i].z==a[i-1].z&&a[i].z==0))f1=0;
		}
		if(f){
			sort(a+1,a+n+1,cmp);
			int cnt=0;
			for(int i=1;i<=n/2;i++){
				cnt+=a[i].x;
			}
			cout<<cnt;
			return 0;
		}
		else if(n==2){
			int a1=a[1].x+a[2].y,a2=a[1].x+a[2].z;
			int a3=a[1].y+a[2].x,a4=a[1].y+a[2].z;
			int a5=a[1].z+a[2].x,a6=a[1].z+a[2].y;
			cout<<max(max(a3,max(a1,a2)),max(a6,max(a4,a5)));
		}
		else if(n==4){

			
		}
	}
	return 0;
}
/*  
    \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/
     |   |   |   |   |   |   |   |   |   |   |   |
    / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \
*/
