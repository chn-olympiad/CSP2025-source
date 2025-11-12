#include <bits/stdc++.h>
using namespace std;
int n,k,a[50010],cnt,vis[50010]={},sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(i!=j&&vis[i]==vis[j]==0) sum=a[i]^a[j];
			if(sum==k) vis[i]=vis[j]=1;
		}
		if(vis[i]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
