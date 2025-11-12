#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[50005];
bool flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}
	return 0;
}
