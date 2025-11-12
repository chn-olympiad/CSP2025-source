#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,a[1000],q,p,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
		}else if(a[i]!=1&&a[i]!=0){
			cout<<n;
			return 0;
		} 
	}
	cout<<cnt;
	return 0;
}
