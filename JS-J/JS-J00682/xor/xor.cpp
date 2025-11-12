#include<bits/stdc++.h>
using namespace std;
int a[510000],b[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	a[1]=(a[1]^k);
	for(int i=2;i<=n;i++){
		if(a[i-1]==0||b[i-1]==k){
			cnt++;
			a[i]=(a[i]^k);
		}
		else{
			a[i]=(a[i-1]^a[i]);
		}
	}
	if(a[n]==0) cnt++;
	cout<<cnt;
	return 0;
}
