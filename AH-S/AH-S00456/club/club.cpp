#include<bits/stdc++.h>
using namespace std;
int t,n,c1,c2,c3;
struct node{
	int x,y,z,p;
}a[100010];
int b[100010],c[100010],d[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		long long ans=0;
		int c1=0,c2=0,c3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				ans+=a[i].x;
				if(a[i].y>=a[i].z) b[++c1]=a[i].y-a[i].x;
				else b[++c1]=a[i].z-a[i].x;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				ans+=a[i].y;
				if(a[i].x>=a[i].z) c[++c2]=a[i].x-a[i].y;
				else c[++c2]=a[i].x-a[i].z;
			}
			else{
				ans+=a[i].z;
				if(a[i].y>=a[i].x) d[++c3]=a[i].y-a[i].z;
				else d[++c3]=a[i].x-a[i].z;
			}
		}
		if(c1>n/2){
			sort(b+1,b+1+c1,greater<int>());
			for(int i=1;i<=c1-n/2;i++) ans+=b[i];
		}
		else if(c2>n/2){
			sort(c+1,c+1+c2,greater<int>());
			for(int i=1;i<=c2-n/2;i++) ans+=c[i];
		}
		else if(c3>n/2){
			sort(d+1,d+1+c3,greater<int>());
			for(int i=1;i<=c3-n/2;i++) ans+=d[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
