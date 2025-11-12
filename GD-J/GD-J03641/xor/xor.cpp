#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n<=2){
		if(a[1]^a[1]==k){
			if(a[2]^a[2]==k){
				cout<<2;
			}else cout<<1;
		}
	}else{
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				long long sm=a[i];
				for(long long qj=i+1;qj<=j;qj++){
					sm^=a[qj];
				}if(sm==k)ans++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
