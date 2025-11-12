#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans=0;
void dfs(long long x,long long cnt){
	for(long long i=x+1;i<=n;i++){
		if(cnt>a[i])ans++;
		dfs(i,cnt+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans;
}
/*
8:51 T1过了大样例
#Shang4Shan3Ruo6Shui4
9:13 T2过样例
11:32 T3样例5死活调不出来 T4糊了个暴搜 
11:50 T3依旧没调对开摆了 
100+100+40+40=280
*/
