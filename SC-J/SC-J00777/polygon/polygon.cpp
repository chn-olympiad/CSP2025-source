#include<bits/stdc++.h>
using namespace std;
const int MON=998244353;
long long n;
int arr[10000];
long long sm;
void dfs(int now,int mx,int geshu,int zonghe){
	if(geshu>=3 && zonghe>mx*2 ){
		sm++;
		sm%=MON;
	}
	for(int i=now+1;i<=n;i++){
		dfs(i,max(arr[i],mx),geshu+1,zonghe+arr[i]);
	}
}
int main(){
	//写freopen(注意空格！！！),提交记得注释，换行用"\n"!!! fc来对比！记得对拍! 
	freopen("polygon.in", "r",stdin);
	freopen("polygon.out", "w",stdout);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=1) x=1;
	}
	for(int i=1;i<=n;i++){
		dfs(i,arr[i],1,arr[i]);
	}
	cout<<sm;
	return 0;
} 