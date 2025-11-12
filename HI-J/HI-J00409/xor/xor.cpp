#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long l=0;l<n;l++){
		for(long long r=l;r<n;r++){
			long long ans=0;
			for(int i=l;i<=r;i++){
				ans=int(ans^a[i]);
			}
			if(ans==k){
				sum++;
				l=r;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
