#include<bits/stdc++.h>
using namespace std;
struct Y{
	int ma,x;
}a[100001];
int xx[100001][4];
int n;
bool cmp(Y a,Y b){
	return a.ma>b.ma;
}
long long cnt=0;
int vis[100001];
void dfs(long long x,long long sum){
	if(x==n+1){
		cnt=max(cnt,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]+1<=n/2){
			vis[i]++;
			dfs(x+1,sum+xx[x][i]);
			vis[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){

		cin>>n;
		int f=0,flag=0;
		for(int i=1;i<=n;i++){
			cin>>xx[i][1]>>xx[i][2]>>xx[i][3];
			a[i].ma==xx[i][1];
			f!=xx[i][2],flag|=xx[i][3];
		}
		if(f&&flag){
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].ma;
			}
			cout<<ans;
		}
		else{
			cnt=0;
			memset(vis,0,sizeof(vis));
			dfs(1,0);
			cout<<cnt<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
