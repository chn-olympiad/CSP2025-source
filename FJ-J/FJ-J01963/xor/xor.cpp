#include<bits/stdc++.h>
using namespace std;
int f,m,n,k,ans;
int a[500010],sum[500010];

void dfs(int l){
	f=0,m=1;
	for(int i=l;i>=m;i--){
		int j=i;
		while(j>=m){
			if((sum[i] xor sum[j-1])==k){
				m=j;
				f=1;
			}
			j--;
		}
	}
	ans+=f;
	if(m==1)  return;
	dfs(m-1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i] xor sum[i-1];
	}
	dfs(n);
	cout<<ans<<endl;
	return 0;
}
