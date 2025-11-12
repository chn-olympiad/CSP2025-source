#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , k , a[500000];
	bool aa = 1 ;
	cin>>n>>k;
	for(int i = 0 ; i< n ; i++){
		cin>>a[i];
		if(a[i]!=1)aa=0;
	}
	if(aa&&k==0){
		if(n%2==0)cout<<1;
		else{
			cout<<0;
		}
	}
	else{
		cout<<" ";
	}
}

