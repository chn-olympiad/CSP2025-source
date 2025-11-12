#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
unsigned int a[MAXN];
bool vis[MAXN];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=0;
			for(int k=i;k<=j;k++){
				s=s^a[k];
			}
			if(s==k&&!vis[i]&&!vis[j]){
				ans++;
				fill(vis+i+1,vis+j+1,1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
