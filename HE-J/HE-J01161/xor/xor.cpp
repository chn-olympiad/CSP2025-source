#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i-1]^a[j]==k){
				ans++;
				i=j+1;
				j=n+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
