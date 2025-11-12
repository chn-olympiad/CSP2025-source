#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans;
	long long cnt = 0;
	long long r;
	for(int i=1;i<=n;i++){
		ans = a[i];
		bool tt = 0;
		if(ans==k){
			cnt++;
			r = i+1;
			tt = 1;
			continue;
		}
		if(tt==0){
			for(int j=i-1;j>=r;j--){
				ans^=a[j];
				if(ans==k){
					cnt++;
					r = i+1;
					break;
				}
			}
		}
			
	}
	cout<<cnt;
	return 0;
}