#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,k,a[N],l,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	l=a[1];
	for(int i=2;i<=n+1;i++){
		if(l == k){
			ans++;
			l=a[i];
		}else{
			l=l^a[i];
		}
	}
	cout<<ans;
	return 0;
}
