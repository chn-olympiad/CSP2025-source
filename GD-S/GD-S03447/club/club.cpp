#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,w;
} a[100010][3];
int t,n,tot[3],ans,ans_now,b[100];
priority_queue<int> q[3];
bool cmp(node q,node h)
{
	return q.w>h.w;
}
//void dfs(int i)
//{
//	if(i>n){
//		if(ans_now==147325){
//			cout<<ans_now<<"\n";
//			for(int j=1;j<=n;j++)
//				cout<<b[j]<<" ";
//			exit(0);
//		}
//		return;
//	}
//	for(int j=0;j<3;j++){
//		if(tot[j]>=n/2)
//			continue;
//		tot[j]++;
//		ans_now+=a[i][j].w;
//		b[i]=j+1;
//		dfs(i+1);
//		tot[j]--;
//		ans_now-=a[i][j].w;
//	}
//}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
//	q[0].push(1);
//	q[0].push(2);
//	cout<<q[0].top();
	while(t--){
		cin>>n;
		tot[0]=0;
		while(!q[0].empty()) q[0].pop();
		tot[1]=0;
		while(!q[1].empty()) q[1].pop();
		tot[2]=0;
		while(!q[2].empty()) q[2].pop();
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j].w;
				a[i][j].c=j;
			}
			sort(a[i],a[i]+3,cmp);
		}
//		tot[0]=0;
//		tot[1]=0;
//		tot[2]=0;
//		dfs(1);
		for(int i=1;i<=n;i++){
			if(tot[a[i][0].c]<n/2){
				ans+=a[i][0].w;
				tot[a[i][0].c]++;
				q[a[i][0].c].push(a[i][1].w-a[i][0].w);
				continue;
			}
			if(q[a[i][0].c].top()+a[i][0].w>a[i][1].w){
				ans+=q[a[i][0].c].top();
				ans+=a[i][0].w;
				q[a[i][0].c].pop();
				q[a[i][0].c].push(a[i][1].w-a[i][0].w);
				continue;
			}
			ans+=a[i][1].w;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
//1
//10
//2020 14533 18961
//2423 15344 16322
//1910 6224 16178
//2038 9963 19722
//8375 10557 5444
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926
