#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,a[500005],sum[500005],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int l=1,r,last=1;
	for(r=1;r<=n;r++){
		l=last;
		while(l<=r){
			if((sum[r]^sum[l-1])==k){
				last=r+1;
				//cout<<l<<' '<<r<<'\n';
				cnt++;
				break;
			}
			l++;
		}
	}
	cout<<cnt;
	return 0;
}
