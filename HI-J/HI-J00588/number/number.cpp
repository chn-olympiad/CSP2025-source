#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	if(n<=9){
		cout<<n;
	}else if(n%10!=0){
	if(n%10>=n/10){
			n=n%10*10+n/10;
			cout<<n;
		}else if(n%10<=n/10){
			cout<<n;
		}	
	}
					
	return 0;
}
