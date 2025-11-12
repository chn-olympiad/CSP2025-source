#include <bits/stdc++.h>
using namespace std;
int n,k,num;
const int N =1e5*5+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
		if(a[i]==k)num++;
		if(a[i]==0)num++;
	}
	cout<<num;
	return 0;
}	