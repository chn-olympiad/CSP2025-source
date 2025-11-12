#include <bits/stdc++.h>
using namespace std;
int n,m,k1[100],c,t,f,k,d,a[10000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		k=0;
		cin>>c;
		if(c==k)k++;
	}
	cout<<k;
	return 0;
}
