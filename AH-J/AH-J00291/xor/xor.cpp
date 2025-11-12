#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5*100000+5],sum[5*100000+5];
void try1(){
	long long cnt=0,x=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k&&x<i){
				cnt++;
				x=j;
			}
		}
	}
	cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	if(n<=2){
		if(a[1]==k&&a[2]==k) cout<<2;
		else if((a[1]^a[2])==k) cout<<1;
		else cout<<0;
		return 0;
	}
	if(k==0){
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i]!=0){
				cnt++;
				i++;
			}
			else if(a[i]==0){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	try1();
	return 0;
}
