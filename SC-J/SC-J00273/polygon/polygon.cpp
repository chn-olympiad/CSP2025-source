#include<bits/stdc++.h>
using namespace std;
const int N=5e3+100;
#define int long long 
int a[N];
int n,ans;
void dfs(int x,int num,int maxnum,int sum){
	//判断出口
	if(num>n) return ; 
	if(num>=3 && sum>2*maxnum) ans++;
	for(int i=x+1;i<=n;i++){
		if(a[i]>maxnum){
			dfs(i,num+1,a[i],sum+a[i]);
		}else{
			dfs(i,num+1,maxnum,sum+a[i]);
		}
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
/*
考虑dfs搜索
最开始的思路是考虑前缀和进行处理
但是中间有需要删除的地方所以舍弃这个方案 

5
1 2 3 4 5
*/
 