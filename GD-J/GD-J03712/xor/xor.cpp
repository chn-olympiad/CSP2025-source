#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int l,r,k,n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
 }
