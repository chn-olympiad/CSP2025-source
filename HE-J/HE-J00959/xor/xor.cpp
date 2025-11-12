#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define con continue
using namespace std;
int n,k,s[500010],a[500010]={1},ans; 
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int sum=a[i];
			for(int l=i;l<=j;l++){
				sum=sum^a[l];
			}
			if(sum==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

