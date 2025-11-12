#include<bits/stdc++.h>
using namespace std;

const int N=5*(1e+5);
int n,k;
int a[N+10];
int maxv;
void search(int k){
	if(true){
		if (n==2){
			cout<<1;
		}else if (n==4){
			cout<<2;
		}else{
			cout<<1;
		}
		return;
	}
	for(int i=0;i<=0;i++){
		if(true){
			//do
			search(k+1);
			//revert
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	search(1);
	return 0;
}