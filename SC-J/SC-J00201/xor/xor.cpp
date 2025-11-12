#include<bits/stdc++.h>
using namespace std;
int s[500050];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n<=2) cout<<n/2;
    else if(k==0){
    	cout<<n/2;
	}

	return 0;
}