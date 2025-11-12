#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,a[10001],b[10001],vis[10001],k,ans;
bool check(int l,int r){
	for(int i=l;i<=r;i++)
		if(vis[i]) return false;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			if((b[j]^b[i-1])==k&&check(i,j)){
				ans++;
				for(int k=i;k<=j;k++)
					vis[k]=1;
				break;
			}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
