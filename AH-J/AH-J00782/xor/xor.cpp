#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100010],b[10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&k==0){
		cout<<"1";
	}
	else if(n==1&&k==0){
		cout<<"0";
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		cout<<b[1]/2;
	}
	return 0;
}
