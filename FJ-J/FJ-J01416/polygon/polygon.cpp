#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		if(n==3){
			long long o=0;
			long long p=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				p+=a[i];
				o=max(o,a[i]);
			}
			if(p>o*2){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
		
	}
	return 0;
}
