#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
long long n,k,l,r,ans,cnt;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		int cnt=a[l];
		for(int r=1;r<=n;r++){
			for(int i=l;i<r;i++){
				cnt=cnt^a[i+1];
			}
			if(cnt==k){
				ans++;
				cnt=0;
			}else{
				cnt=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
