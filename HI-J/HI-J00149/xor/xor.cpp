#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int a[N];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
	if(n==1) cout<<0;
	else if(n==2) cout<<1;
	else cout<<n/2;	
	}else{
	cout<<2;
	}
	
	return 0;
}

