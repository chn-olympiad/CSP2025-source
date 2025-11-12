#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
}mac[100050],secm[100050];
int t,n,ans,s[100050],a[100050][4];
bool cmp(node x,node y){
	return x.val<y.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(mac,0,sizeof(mac));
		memset(secm,0,sizeof(secm));
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>=mac[i].val){
					secm[i].val=mac[i].val;					
					mac[i].val=a[i][j];
					mac[i].id=j;
				}else if(secm[i].val<a[i][j]){
					secm[i].val=a[i][j];
				}
			}
		}
		sort(mac+1,mac+n+1,cmp);
		for(int i=n;i>=1;i--){
			if(s[1]==n/2){
				if(mac[i].id==1){
					ans+=secm[i].val;
					continue;
				}
			}
			if(s[2]==n/2){
				if(mac[i].id==2){
					ans+=secm[i].val;
					continue;
				}
			}
			if(s[3]==n/2){
				if(mac[i].id==3){
					ans+=secm[i].val;
					continue;
				}
			}
			ans+=mac[i].val;
			s[mac[i].id]++;
		}
		printf("%d\n",ans);
	}
}
