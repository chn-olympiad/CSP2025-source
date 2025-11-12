#include<bits/stdc++.h>
using namespace std;
int a[100009]
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,l=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)l=1;
	}
	cout<<l;
}