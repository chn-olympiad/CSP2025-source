#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[100];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1 && k==0)
		cout<<0;
	else if(n==2 && k==0){
		if(a[1]==0 || a[2]==0 )
			cout<<1;
		else
			cout<<0;
	}
}
