#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];
int tot;
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int o=a[l];
			for(int u=l+1;u<=r;u++){
				o=o^a[u];
			}
			if(o==k){
				int flag=0;
				for(int i=l;i<=r;i++){
					if(vis[i]){
						flag=1;
					}
				}
				if(flag){
					break;
				}
				for(int i=l;i<=r;i++){
					vis[i]=1;
				}
				cnt++;
			
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
