#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],sum=0,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
