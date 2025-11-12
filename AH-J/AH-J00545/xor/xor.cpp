#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int main(){
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int w=0;
		for(int j=i;j<=n;j++){
			w=(w^a[j]);
			if(w==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
