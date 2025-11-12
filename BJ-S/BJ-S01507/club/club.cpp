#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z;
}t[N];
int f[5];
struct Node{
	int x,y;
}a[5];
bool cmp(node x,node y){
	int x1=max(x.x,max(x.y,x.z)),y1=max(y.x,max(y.y,y.z)),x2,y2;
	if(x1==x.x)x2=max(x.y,x.z);
	else if(x1==x.y)x2=max(x.x,x.z);
	else if(x1==x.z)x2=max(x.x,x.y);
	if(y1==y.x)y2=max(y.y,y.z);
	else if(y1==y.y)y2=max(y.x,y.z);
	else if(y1==y.z)y2=max(y.x,y.y);
	return x1-x2>y1-y2;
}  
bool cmp2(Node x,Node y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		f[1]=f[2]=f[3]=n/2;
		for(int i=1;i<=n;i++)cin>>t[i].x>>t[i].y>>t[i].z;
		sort(t+1,t+1+n,cmp);
		for(int i=1;i<=n;i++){
			a[1].x=t[i].x;
			a[1].y=1;
			a[2].x=t[i].y;
			a[2].y=2;
			a[3].x=t[i].z;
			a[3].y=3;
			sort(a+1,a+4,cmp2);
			if(f[a[1].y]){
				f[a[1].y]--;
				ans+=a[1].x;
			}else{
				if(f[a[2].y]){
					f[a[2].y]--;
					ans+=a[2].x;
				}else{
					f[a[3].y]--;
					ans+=a[3].x;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
