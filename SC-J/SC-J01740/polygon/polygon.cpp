#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int x,int cnt,int sum,int maxn){	
	if(x==n+1){
		if(cnt>=3&&sum>2*maxn) ans++;
		return;
	}
	dfs(x+1,cnt+1,sum+a[x],max(maxn,a[x]));
	dfs(x+1,cnt,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 
/*
密码：#Shang4Shan3Ruo6Shui4
2^n暴力,竟然能骗40pts?!!
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

*/