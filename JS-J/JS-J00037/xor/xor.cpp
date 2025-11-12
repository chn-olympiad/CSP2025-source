#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],pre[500005],sum;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			sum++;
			vis[i]=1;
		}
	}
	pre[1]=a[1];
	for(int i=2;i<=n;i++)pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		if(vis[i]==1||a[i]==0)continue;
		for(int j=i;j<=n;j++){
			if(vis[j]==1)break;
			long long ans=pre[j]^pre[i-1];
			if(ans==k){
				for(int z=i;z<=j;z++)vis[z]=1;
				sum++;
				break;
			}
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
