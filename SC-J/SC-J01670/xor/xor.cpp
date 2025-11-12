#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,b[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=n,p=0;
	for(int i=n;i>=1;i--){
		int p=0;
		for(int j=i;j<=q;j++){
			p=p^a[j];
			if(p==k){
				b[i]=j;
				q=j-1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=0){
			ans++;
			i=b[i];
		}
	}
	cout<<ans;
	return 0;
}