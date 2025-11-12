#include<bits/stdc++.h>
using namespace std;
long long a[5001],n,k,i,b[5001],cnt,s;
void dfs(long long p,long long k,long long s1){
	if(p>i){
		sort(b+1,b+cnt+1);
		if(s1>2*b[cnt]) s++;
		return;
	}
	b[++cnt]=a[k];
	for(long long j=k+1;j<=n;j++)
		dfs(p+1,j,s1+a[j]);
	cnt--;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=3;i<=n;i++){
		cnt=0;
		for(long long j=1;j<=n-i+1;j++)
			dfs(1,j,a[j]);
	}
	cout<<s;
	return 0;
}
