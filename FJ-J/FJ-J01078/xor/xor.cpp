#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
bool a[N];
int n,k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==a[i]) 
			sum++;
	}
	cout<<sum;
	return 0;
}
