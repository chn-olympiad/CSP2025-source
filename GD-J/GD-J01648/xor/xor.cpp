#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int tep=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tep+=a[i];
	}
	if(tep==n&&k==0){
		cout<<n/2;
	}
	return 0;
}
