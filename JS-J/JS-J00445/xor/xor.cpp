#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,sum1=0,sum2=0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		int x;
		cin>>x;
		if(x) sum1++;
		else sum2++;
	}
	
	if(k == 1) cout<<sum1;
	else cout<<sum2 + sum1/2;
	
	return 0;
}
