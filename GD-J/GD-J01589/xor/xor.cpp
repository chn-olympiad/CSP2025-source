#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,ans1;
int cz(int l,int r){
	if(r<l)return 0;
	int nx=0,ans=0;
	for(int i=l;i<=r;i++){
		nx=(int)(nx^a[i]);
		if(nx==k){
			ans+=max(1,cz(l+1,i));
			nx=0;
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false),cout.tie(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans1=cz(1,n);
	cout<<ans1;
	return 0;
}
