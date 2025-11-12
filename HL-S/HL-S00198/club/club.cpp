#include <bits/stdc++.h> 
using namespace std;
int aa[100010][3];
struct node{
	int x,y,z;
};
bool cmp(node a,node b){
	return (a.x+a.y+a.z)<(b.x+b.y+b.z);
}
bool cmp1(node a,node b){
	return (a.x+a.y+a.z)>(b.x+b.y+b.z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int cnt[4];
		node e[100010];
		int n;
		cin>>n;
		int flag=1,flag1=1;//1 3   3
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			e[i].x=x;
			e[i].y=y;
			e[i].z=z;
			if(x!=0) flag=0;
			if(z!=0) flag1=0;
		}
		if(flag){
			sort(e+1,e+1+n,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=e[i].y;
			}
			cout<<ans<<'\n';
		}else if(flag1){
			sort(e+1,e+1+n,cmp1);
			int ans=0;
			for(int i=1;i<=n;i++){
				if(cnt[1]<n/2&&cnt[2]<n/2){
					ans+=max(e[i].x,e[i].y);
					if(e[i].x>e[i].y) cnt[1]++;
					else cnt[2]++;
				}else if(cnt[1]==n/2){
					ans+=e[i].y;
					cnt[2]++;
				}else if(cnt[2]==n/2){
					ans+=e[i].x;
					cnt[1]++;
				}
			}
			cout<<ans<<'\n';
		}else{
			sort(e+1,e+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n;i++){
				if(cnt[1]<n/2&&cnt[2]<n/2&&cnt[3]<n/2){
					ans+=max(e[i].x,max(e[i].y,e[i].z));
					if(e[i].x>e[i].y&&e[i].x>e[i].z) cnt[1]++;
					else if(e[i].y>e[i].x&&e[i].y>e[i].z) cnt[2]++;
					else cnt[3]++;
				}else if(cnt[1]==n/2){
					ans+=max(e[i].y,e[i].z);
					if(e[i].y>e[i].z) cnt[2]++;
					else cnt[3]++;
				}else if(cnt[2]==n/2){
					ans+=max(e[i].x,e[i].z);
					if(e[i].z>e[i].x) cnt[3]++;
					else cnt[1]++;
				}else{
					ans+=max(e[i].x,e[i].y);
					if(e[i].y>e[i].x) cnt[2]++;
					else cnt[1]++;
				}
			}
			cout<<ans<<'\n';
		}
	} 
	return 0;
}
