#include <bits/stdc++.h>
using namespace std;
int a[5005],n,used[5005],sum,maxn=-1,sumn,i;
void dfs(int k){
	if(k==i+1 and sumn>2*maxn)  sum=(sum+1)%998244353,maxn=-1;
	else if(k==i and !(sumn>2*maxn))  return;
	for (int j=k;j<=n;j++){
		if(used[j]==0){
			used[j]=1;
			sumn+=a[j];
			int maa=maxn;
			maxn=max(maxn,a[j]);
			dfs(k+1);
			maxn=maa;
			sumn-=a[j];
			used[j]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)  cin >> a[i];
	for (i=3;i<=n;i++)  dfs(1);
	cout << sum;
	return 0;
}
