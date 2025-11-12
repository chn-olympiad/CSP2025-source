#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	long long k=0;
	for(long long l=1,r=1;r<=n+1;){
		if(l==r){
			if(a[r]==m&&r<=n){
				cnt++;
				r++;
				l++;
				k=0;
			}
			else{
				k=k^a[r];
				r++;
			}
		}
		else if(k==m){
			cnt++;
			k=0;
			r++;
			l=r;
		}
		else{
			if(a[r]==m){
				l++;
				k=k^a[l];
			}
			else{
				k=k^a[r];
				r++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
