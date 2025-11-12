#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,a[500005],cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=l;
	while(r){
		if(r==n){
			r=-1;
			cnt++;
		}
		int sum;
		for(int i=l;i<=r;i++){
			sum^=a[i];
		}
		if(sum==k){
			l=r+1;
			r=l;
			cnt++;
		}
	}
	cout<<cnt-3;
	return 0;
}