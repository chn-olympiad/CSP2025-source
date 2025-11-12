#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		int cur=a[i];
		if(vis[i])continue;
		vis[i]=1;
		for (int j=i;j<=n;j++){
			if(cur==k){
				ans++;
				for (int k=1;k<=j-1;k++)vis[k]=1;
				break;
			}
			int pos=j;
			while(vis[pos]&&pos<=n){
				pos++;
			}
			if(pos>n){
				cout << ans;
				return 0;
			}
			cur^=a[pos];
			j=pos;
		}
	}
    cout <<ans; 
	return 0;
}
