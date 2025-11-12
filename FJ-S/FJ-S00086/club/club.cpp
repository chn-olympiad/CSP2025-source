#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans=0;
bool xy=1;
void za(int s,int x,int y,int z,int cnt){
	if(s==n){
		ans=max(ans,cnt);
		return ;
	}
	if(a[s][1]>=a[s][2]||a[s][1]>=a[s][3]){
		if(x<n/2)za(s+1,x+1,y,z,cnt+a[s][1]);
	}
	if(a[s][2]>=a[s][1]||a[s][2]>=a[s][3]){
		if(y<n/2)za(s+1,x,y+1,z,cnt+a[s][2]);
	}
	if(a[s][3]>=a[s][1]||a[s][3]>=a[s][2]){
		if(z<n/2)za(s+1,x,y,z+1,cnt+a[s][3]);
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
			scanf("%d",&a[i][3]);
		}
		ans=0;
		za(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
