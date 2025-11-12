#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
};
int t;
bool cmp(node a,node b){
	return max(a.x,max(a.y,a.z))>max(b.x,max(b.y,b.z));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,x1=0,y1=0,z1=0;
		long long ans=0;
	    cin>>n;
	    node a[100001];
	    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	    sort(a+1,a+n+1,cmp);
	    for(int i=1;i<=n;i++){
	    	int r=max(a[i].x,max(a[i].y,a[i].z));
			if(r==a[i].x&&x1<n/2){
	    		ans+=r;
	    		x1++;
			}
			if(r==a[i].y&&y1<n/2){
	    		ans+=r;
	    		y1++;
			}
			if(r==a[i].z&&z1<n/2){
	    		ans+=r;
	    		z1++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
