#include<bits/stdc++.h>
using namespace std;
long long n,k,flag=1,cnt=0;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			flag=0;
		}
		if(a[i]==1){
			cnt++;
		}
	}
	if(k==0&&flag==1){
		cout<<n/2;
	}
	if(k==1){
		cout<<cnt;
	}
	return 0;
}

