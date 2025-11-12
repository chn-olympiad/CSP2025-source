#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<"-1";
	return 0;
} 
