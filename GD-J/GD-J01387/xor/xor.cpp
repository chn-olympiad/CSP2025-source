#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long l,r;
long long a[500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			long long sum=a[l];
			for(int i=l+1;i<=r;i++){
				sum=sum^a[i];
			}
			if(sum==k)ans++;
		}
	}
	cout<<ans;
	return 0; 
}
