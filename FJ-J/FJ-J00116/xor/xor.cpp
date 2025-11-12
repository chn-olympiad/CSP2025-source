#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],vis[500001],tmp,cnt;
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			tmp=f=0;
			for(int l=j-i+1;l<=j;l++){
				if(vis[l]){
					f=1;
					break;
				}
				tmp=tmp^a[l];
			}
			if(!f){
				if(tmp==k){
					cnt++;
					for(int l=j-i+1;l<=j;l++){
						vis[l]=1;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
