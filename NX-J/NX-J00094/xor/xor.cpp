#include <bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(a[1]==k){
			s++;
		}
		else if(a[2]==k){
			s++;
		}
		else if(a[1]==a[2]){
			s++;
		}
	}
	cout<<s;
    return 0;
}

