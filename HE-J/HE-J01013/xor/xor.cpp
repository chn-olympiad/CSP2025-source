#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;long long k;bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(flag!=1)flag=0;
	}
	if(flag){cout<<n/2;return 0;}
	return 0;
}
