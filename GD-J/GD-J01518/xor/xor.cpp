#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500007];
bool pd(long long l,long long r){
	long long ans=a[l];
	for(long long i=l+1;i<=r;i++){
		ans=ans^a[i];
	}
	return ans==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long i,j,ans=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;){
		for(j=i;j<=n;j++){
			if(pd(i,j)){
				i=j+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
