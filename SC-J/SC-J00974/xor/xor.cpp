#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	__int64 n,k,ans1=0;cin>>n>>k;
	vector<int>A(n+1);
	for(int i=1;i<=n;i++)cin>>A[i];
	int l=1,r=1,a=1;
	for(;l<=n&&r<=n;){
		int ans=A[l];
		for(int i=l+1;i<=r;i++){
			ans=ans xor A[i];
		}
		if(ans==k){
			ans1++;
			l=r;
		}
		if(r==l)a=1;
		if(r==n)a=0;
		if(l>=n&&r>=n)break;
		if(a==1)r++;
		if(a==0)l++;
	}
	cout<<ans1;
	return 0;
}