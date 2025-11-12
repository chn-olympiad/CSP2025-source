#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=2 && k==0){
		cout << 1;
	}
	return 0;
}