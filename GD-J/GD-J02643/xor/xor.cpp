#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		i++;
		while(x!=k and i<=n){
			x=x^a[i];
			i++;
		} 
		if(i==n+1){
			break;
		}
		i--;
		if(x==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
