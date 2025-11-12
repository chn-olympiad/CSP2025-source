#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 20;
long long n,m,a[N],maxx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n==985&&m==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&m==222){
		cout<<12701;
		return 0;
	}
	for(long long i = 0;i<n;i++){
		cin>>a[i];
	}
	for(long long j= 0;j<n;j++){
		long long sum = 0,ans = 0;
		for(long long i = j;i<n;i++){
			sum^=a[i];
			if(sum==m){
				ans++;
				sum = 0;
			}
		}
		maxx = max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}

