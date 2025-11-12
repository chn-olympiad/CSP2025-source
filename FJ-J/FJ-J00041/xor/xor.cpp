#include<bits/stdc++.h>
using namespace std;
long long n,x,k,l,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		scanf("%d",&x);
		l^=x;
		if(l==k){
			ans++;
			l=0;
		}
	}
	cout<<ans;
	return 0;
}
