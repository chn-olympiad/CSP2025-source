#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],zero,one,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			zero++;
		}else{
			one++;
		}
	}
	if(k==0){
		cout<<zero + one/2;
	}else{
		cout<<one;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
