#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
long long a[1000000+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(a[1]==m){
		sum++;
		a[1]=-1;
	}
	for(long long i=2;i<=n;i++){
		if(a[i]==m){
			sum++;
			a[i]=-1;
			continue;
		}
		else if(a[i]>=0 and a[i-1]>=0){
			a[i]=(a[i] xor a[i-1]);
			if(a[i]==m){
				sum++;
				a[i]=-1;
			}
		}
	}
	cout<<sum;
	return 0;
}
/*
5 1 2 3 4 5
4 2 2 1 0 3
4 3 2 1 0 3

*/
