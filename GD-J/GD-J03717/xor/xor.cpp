#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,wei=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	for(int l=1,r=1;l<=n&&r<=n;){
		if(l>r){
			r++;
			l=wei;
		}
		else if((a[r]^a[r-1])==k){
			ans++;
			l=r+1;
			wei=l;
			r++;
		}
		else if((a[l-1]^a[r])==k){
			ans++;
			l=r+1;
			wei=l;
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
