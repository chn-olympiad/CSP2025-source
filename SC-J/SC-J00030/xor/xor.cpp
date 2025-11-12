#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=1,ans=0;
	int p=a[l];
	while(r<=n){
		if(p==k){
			ans++;
			r++;
			l=r;
			p=a[r];
			continue;
		}
		r++;
		p^=a[r];
	}
	cout<<ans;
	return 0;
}