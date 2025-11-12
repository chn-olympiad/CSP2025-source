#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,k;
int ans=0;
int f(int l,int r){
	if(l>r) return 0;
	if(l==r) return (a[l]==k?1:0);
	int ans=0;
	int mid=(l+r)/2;
	ans=max(ans,f(l,mid));
	ans=max(ans,f(mid+1,r));
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int b=0,c=0;
	cin>>n>>k;
	for(int i=1,t;i<=n;i++){
		cin>>t;
		if(t==1) b++;
		if(t==0) c++;
		a.push_back(t);
	}
	if(b==n) cout<<(k==1?n:0);
	else if(c==n) cout<<(k==0?n:0);
	else cout<<f(1,n);

	return 0;
}
