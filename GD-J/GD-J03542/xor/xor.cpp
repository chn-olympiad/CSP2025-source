#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn],pre[maxn];
bool vis[maxn];
bool check(int x,int y){
	for(int i=x;i<=y;i++)
		if(vis[i]) return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int j=1;j<=n;j++) pre[j]=pre[j-1]^a[j];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(pre[j]^pre[j-i-1] && check(j-i,j)){
				ans++;
				for(int k=j-i;k<=j;k++) vis[k]=1;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
