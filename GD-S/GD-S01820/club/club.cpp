#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4];
priority_queue<int> q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--){
		for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		int n;
		scanf("%d",&n);
		int cnt1=0,cnt2=0,cnt3=0,sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt1++,sum+=a[i][1];
				q[1].push(max(a[i][2],a[i][3])-a[i][1]);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt2++,sum+=a[i][2];
				q[2].push(max(a[i][1],a[i][3])-a[i][2]);
			}else{
				cnt3++,sum+=a[i][3];
				q[3].push(max(a[i][1],a[i][2])-a[i][3]);
			}
		}
		while(q[1].size()>n/2){
			sum+=q[1].top();q[1].pop();
		}
		while(q[2].size()>n/2){
			sum+=q[2].top();q[2].pop();
		}
		while(q[3].size()>n/2){
			sum+=q[3].top();q[3].pop();
		}
		printf("%d\n",sum);
	}
	return 0;
}
