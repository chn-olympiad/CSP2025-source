#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node1{
	int x,y,z,id;
	int maxn=0;
}a[N];
bool cmp1(node1 A, node1 B){
	return A.x>B.x;
}
bool cmp2(node1 A, node1 B){
	return A.y>B.y;
}
bool cmp3(node1 A, node1 B){
	return A.z>B.z;
}
bool vis[N];
int ans,cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	int t;
	cin>>t;
	while(t--){
		ans=0,cnt=0;
		memset(vis,0,sizeof(vis));
		int n;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1; i<=n; i++){
			if(cnt==n/2)break;
			if(a[i].x==a[i].maxn){
				vis[a[i].id]=1;
				ans+=a[i].x;
				cnt++;
 
			}
		}
		sort(a+1,a+n+1,cmp2);
		cnt=0;
		for(int i=1; i<=n; i++){
			if(vis[a[i].id])continue;
			if(cnt==n/2)break;
			if(max(a[i].y,a[i].z)==a[i].y){
				vis[a[i].id]=1;
				ans+=a[i].y; 
				cnt++;
			}
		}
		cnt=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1; i<=n; i++){
			if(vis[a[i].id])continue;
			if(cnt==n/2)break;
			vis[a[i].id]=1;
			ans+=a[i].z;
	//		cout<<a[i].id<<endl;
			cnt++;
		}
		if(n==2){
			if(a[1].x==a[1].maxn&&a[2].x==a[2].maxn){
				if(a[1].x>max(a[1].z,a[1].y)+a[2].x){
					ans=max(a[1].x,ans);
				}else{
					ans=max(ans,max(a[1].z,a[1].y)+a[2].x);
				}
				if(a[2].x>max(a[2].z,a[2].y)+a[1].x){
					ans=max(ans,a[2].x);
				}else{
					ans=max(ans,max(a[2].z,a[2].y)+a[1].x);
				}
			}
			if(a[1].y==a[1].maxn&&a[2].y==a[2].maxn){
				if(a[1].y>max(a[1].z,a[1].x)+a[2].y){
					ans=max(ans,a[2].y);
				}else{
					ans=max(ans,max(a[1].z,a[1].x)+a[2].y);
				}
				if(a[2].y>max(a[2].z,a[2].x)+a[1].y){
					ans=max(ans,a[1].y);
				}else{
					ans=max(ans,max(a[2].z,a[2].x)+a[1].y);
				}
			}
			if(a[1].z==a[1].maxn&&a[2].z==a[2].maxn){
				if(a[1].z>max(a[1].x,a[1].y)+a[2].z){
					ans=max(ans,a[2].z);
				}else{
					ans=max(ans,max(a[1].x,a[1].y)+a[2].z);
				}
				if(a[2].z>max(a[2].x,a[2].y)+a[1].z){
					ans=max(ans,a[2].z);
				}else{
					ans=max(ans,max(a[2].x,a[2].y)+a[1].z);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
