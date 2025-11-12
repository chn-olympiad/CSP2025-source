#include<bits/stdc++.h>
using namespace std;
int n,a[5010],d[5010],cnt,b[5010],dp[5010],mod=998244353;
bool calc(int i){
	int tot=0,maxn=0,flag=0;
	for(int j=0;j<n;j++){
		if(i&(1<<j)){ 
			flag++;
			tot+=a[j+1];
			maxn=max(maxn,a[j+1]);
		}
	}
	if(flag<3) return false;
	if(tot>maxn*2) return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=20){
		for(int i=1;i<(1<<n);i++){
			if(calc(i)) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
