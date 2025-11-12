#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int x,y,z;
}a[100005];
bool cmp(node t1,node t2){
	return t1.x>t2.x;
}
int n,mode,max1=-1;
void dfs(int x,int t1,int t2,int t3,int sum){
	if(x==n+1){
		max1=max(max1,sum);
		return ;
	}
	if(t1+1<=n/2)dfs(x+1,t1+1,t2,t3,sum+a[x].x);
	if(t2+1<=n/2)dfs(x+1,t1,t2+1,t3,sum+a[x].y);
	if(t3+1<=n/2)dfs(x+1,t1,t2,t3+1,sum+a[x].z);
	dfs(x+1,1,0,0,a[x].x);
	dfs(x+1,0,1,0,a[x].y);
	dfs(x+1,0,0,1,a[x].z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0){
				flag=1;
			}
		}
		if(flag==0){
			sort(a+1,a+n+1,cmp);
			ll sum=0;
			for(int i=1;i<=n/2;i++) sum+=a[i].x;
			cout<<sum<<endl;
			continue;
		}
		max1=-1;
		dfs(1,0,0,0,0);
		cout<<max1<<endl;
	}
	return 0;
}
