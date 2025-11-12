#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
int l,r;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=0)flag=false;
	}
	if(flag=true)cout<<n/2;
}
