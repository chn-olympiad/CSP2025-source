#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N],sum[N],ans=0,last=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int r=1;r<=n;r++){
		if(a[r]==k){
			ans++;
			last=r;					
		}
		for(int l=r-1;l>=last;l--){
			int x=sum[r]^sum[l];
			if(x==k){
				ans++;
				last=r;
				break;
			}			
		}		
	}
	cout<<ans;
	return 0;
}