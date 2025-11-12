#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int flag=a[0];
	bool flag1=true;
	for(int i=1;i<n;i++){
		if(a[i]!=flag){
			flag1=false;
		}
	}
	if(flag1){
		cout<<n;
	}

	return 0;
}