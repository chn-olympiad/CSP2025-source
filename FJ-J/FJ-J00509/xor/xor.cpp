#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out ","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n];
	
	return 0;
}
