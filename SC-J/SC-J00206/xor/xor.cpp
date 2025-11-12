#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f,ans,st=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long r=1;r<=n;r++){
		for(long long l=r;l>=st;l--){
			if(l==r) f=a[l];
			else f=f^a[l];
			if(f==k){
				ans++;
				st=r+1,r=st-1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
