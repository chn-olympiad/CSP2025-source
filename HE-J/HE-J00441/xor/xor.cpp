#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m,a[100001],x;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m=max(a[i],a[i+1]);
	}
	cout<<m-1;
}
