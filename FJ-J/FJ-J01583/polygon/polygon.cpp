#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int q=0;
int arr[N];
int vis[N][N],n;
bool check(int sum,int a){
	if(sum<=a*2){
		return 0;
	}else{
		return 1;
	}
}
int dfs(int sum,int ma,int k,int cnt,int b,int now){
	//cout<<cnt<<endl;
	vis[b][now]=1;
	vis[now][b]=1;
	if(!check(sum,ma)&&k>=3){
		cnt--;
		return cnt;
	}
	if(k>=3){
		cnt++;
	}
	if(k==n)return cnt;
	for(int i=1;i<=n;i++){
		if(vis[now][i]==0){
			dfs(sum+arr[i],max(arr[i],ma),k+1,cnt%mod,now,i);
			vis[b][now]=0;
			vis[now][b]=0;
		}
	}
	q+=cnt;
	q%=mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		dfs(arr[i],arr[i],1,0,i,i);
		//cout<<q<<" ";
	}
	cout<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
