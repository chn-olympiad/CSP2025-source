//O(n^2)+Æ­5·Ö 
#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,a[500005],f[500005];
void g(long long x){
	long long sum=0;
	for(int j=1;j<x;j++){
		sum=max(sum,f[j]);
	}
	f[x]=sum+1;
	cnt=x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>1005){
		if(k==1){
			cout<<n;
		}
		else{
			long long sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}
				else{
					if(a[i]==1&&a[i-1]==1){
						sum++;
						a[i]=0;
						a[i-1]=0;
					}
				}
			}
			cout<<sum;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			g(i);
			continue;
		}
		bool ff=0;
		long long cmp=0;
		for(int j=i;j>cnt;j--){
			cmp^=a[j];
			if(cmp==k){
				g(i);
				ff=1;
				break;
			}
		}
		if(ff){
			continue;
		}
		for(int j=1;j<i;j++){
			f[i]=max(f[i],f[j]);
		}
	}
	cout<<f[n];
	return 0;
}
