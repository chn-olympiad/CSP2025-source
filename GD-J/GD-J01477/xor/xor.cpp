#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt=0,sum_xor=a[1],l=1,r=1;
	for(int i=1;i<=n;i++){
		if(sum_xor==k){
			cnt++;
			r++;
			l=r;
			if(l>n) break;
			sum_xor=a[l];
		}else if(r<n){
			r++;
			sum_xor=(sum_xor xor a[r]);
		}
		else break;
	}
	cout<<cnt;
	return 0;
}
