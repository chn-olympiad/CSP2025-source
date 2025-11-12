#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool vis[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,b,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b=a[i];
		for(int j=i;j<=n;j++){
			if(!vis[j]){
				continue;
			}
			if(b==k){
				cout<<j-i+1;
				for(int w=j;w>=i;w--){
					vis[w]=1;
				}
				sum++;
			}
			b=b^a[j];
		}
	}
	cout<<sum;
	return 0;
}
