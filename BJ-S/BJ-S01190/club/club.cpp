#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N][4],ans,num[4];
int n,T;
priority_queue<ll>qq[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				num[1]++;
				qq[1].push(-(a[i][1]-max(a[i][2],a[i][3])));
			}
			if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				num[2]++;
				qq[2].push(-(a[i][2]-max(a[i][1],a[i][3])));
			}
			if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1]){
				num[3]++;
				qq[3].push(-(a[i][3]-max(a[i][1],a[i][2])));
			}
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		for(int i=1;i<=3;i++){
			while(num[i]>n/2){
				ans+=qq[i].top();
				qq[i].pop();
				num[i]--;
			}
		}
		printf("%d\n",ans);
		memset(a,0,sizeof(a));
		for(int i=1;i<=3;i++)while(!qq[i].empty())qq[i].pop();
		num[1]=num[2]=num[3]=ans=0;
	}
	
	return 0;
}