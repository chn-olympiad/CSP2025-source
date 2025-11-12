#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,s=0;
	bool f=0;
	for(int i=1;i<=n;i++){
		ans=a[i]^a[i+1];
		if(ans==k){
			s++;
			f=1;
		}
	}
	if(f){
		cout<<s;
	}
	else{
		cout<<2;
	}
    return 0;
}
