#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int one1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			one1++;
		}
	}
	if(k==0){
		cout<<one1/2;
	}else if(k==1){
		cout<<one1;
	}
	return 0;
}
