#include<iostream>
using namespace std;
long long n,k;
long long  a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxn=-1;
	for(int ll=1;ll<=n;ll++){
		long long cnt=0;
		for(int i=ll;i<=n;i++){
			for(int j=i;j<=n;j++){
				long long sum=0;
				for(int kk=i;kk<=j;kk++){
					sum=(sum^a[kk]);
				}
				if(sum==k){
					cnt++;
					i=j+1;
				}
			}
		}
		maxn=max(maxn,cnt);
}
	cout<<maxn;
	return 0;
}
