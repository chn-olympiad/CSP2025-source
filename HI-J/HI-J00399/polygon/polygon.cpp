#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,a[10005],x=0,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(m>=3){
		if(a[i]>x*2){
			if(1<=i&&i<=n){
				ans+=i;

			}
		}	
		}
	}
	cout<<ans%M;
	return 0;
}

