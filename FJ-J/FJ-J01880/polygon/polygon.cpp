#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long cnt;
const int quyu=998244353;
long long bigsum,bigmmx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bigsum+=a[i];
		bigmmx=max(bigmmx,a[i]);
	}
	if(n==3){
		if(bigsum>2*bigmmx){
			cnt++;
		}
		cout<<cnt%quyu;
		return 0;
	}
	if(bigmmx==1){
		cout << ((n+1)*n/2-3)%quyu;
		return 0;
	}
	for(int k=3;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			long long j=i+k-1;
			long long sum=0;
			long long mmx=-1;
			for(int p=i;p<=j;p++){
				sum+=a[p];
				mmx=max(mmx,a[p]);
			}
			if(sum>2*mmx){
				cnt++;
			}
		}
	}
	cout<<cnt%quyu;
	return 0;
}
