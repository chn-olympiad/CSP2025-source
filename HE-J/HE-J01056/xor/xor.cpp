#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i = 1;i<=n;i++) cin >>a[i];
	long long l = 1,r = 1,lastr = 0;
	while(l<=r){
		long long cnt = a[l];
		for(int i = l+1;i<=r;i++){
			if(l==r){
				break;
			}
			cnt ^= a[i];
		}
		if(cnt==k&&l>lastr){
			ans++;
			lastr = r;
		}
		r++;
		if(r>n){
			l++;
			if(l>n){
				cout <<ans;
				break;
			}
			r = l;
		}
	}
	return 0;
}

