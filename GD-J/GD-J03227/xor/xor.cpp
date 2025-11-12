#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
long long ans;
long long k;
int a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){ 
			cnt=0;
			ans++;
			continue; 
		}
		cnt=cnt xor a[i];
		if(cnt==k){
			cnt=0;
			ans++;
		} 
	}
	cout<<ans; 
	return 0;
 } 
