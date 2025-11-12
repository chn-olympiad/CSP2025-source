#include<bits/stdc++.h> 
using namespace std;
const int N=5010;
const long long p=998244353;
int n,arr[N];
long long ans=0;
int mark[5010];
void dfs(int dep,int num){
	if(dep==n+1){
		int sum=0,mx=-1;
		for(int i=1;i<=n;i++){
		//	cout<<mark[i]<<" ";
			if(mark[i]){
				sum+=arr[i];
				mx=max(arr[i],mx);
			//	cout<<arr[i]<<" ";
			} 
		}
		if(sum>mx*2) ans++;
	//	cout<<'\n';
		return ;
	}
	//选择这一个 
	mark[dep]=1;
	dfs(dep+1,num+1);
	//不选这一个
	if(n-dep<3-num) return ; 
	mark[dep]=0;
	dfs(dep+1,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	dfs(1,0);
	cout<<ans%p;
	return 0;
}
//#Shang4Shan3Ruo6Shui4

