#include<bits/stdc++.h>
using namespace std;
long long n,k,a[50010],ans;
bool use[50010];
long long xors(long long l,long long r){
	long long tmp=a[l];
	for(long long i=l+1;i<=r;i++){
		tmp=tmp^a[i];
	}
	return tmp;
} 
bool check(long long l,long long r){
	for(long long i=l;i<=r;i++){
		if(use[i])
		return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long j=0;j<n;j++){
		for(long long l=1;l+j<=n;l++){
			if(check(l,l+j)&&xors(l,l+j)==k){
				ans++;
				for(long long i=l;i<=l+j;i++){
					use[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
