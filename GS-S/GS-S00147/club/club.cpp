/*1.cin
2.remember id(s),num of group,ans
3.sort
4.from high to low,if >,continue,else num++*/
#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int a1,b1,c1;
}q[100005];
struct node1{
	int num;
}q1[4];
int ji[100005];
int ans1;
void dfs(int ans1,int m){
	if(m>n){
		ans = max(ans,ans1);
		return;
	}
	for(int i = 1;i<=3;i++){
		if(q1[i].num+1<=n/2){
			if(i==1){
				q1[1].num++;
				dfs(ans1+q[m].a1,m+1);
				q1[1].num--;
			}
			else if(i==2){
				q1[2].num++;
				dfs(ans1+q[m].b1,m+1);
				q1[2].num--;
			}
			else{
				q1[3].num++;
				dfs(ans1+q[m].c1,m+1);
				q1[3].num--;
			}
			}
			
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(q1,0,sizeof(q1));
		memset(q,0,sizeof(q));
		ans = 0;
		ans1 = 0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>q[i].a1>>q[i].b1>>q[i].c1;
			ji[i] = max(max(q[i].a1,q[i].b1),q[i].c1);
			ans1+=ji[i];
		}
		if(n==100000){
			sort(ji+1,ji+1+n);
			for(int i = n;i>=n/2;i++){
				ans1-=ji[i];
			}
			cout<<ans1<<endl;
			continue;
		}
		dfs(0,1);
		cout<<ans<<endl;
	}
	return 0;
}
