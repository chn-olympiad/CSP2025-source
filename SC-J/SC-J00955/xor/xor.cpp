#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0; cin>>n>>k;
	vector<int> a(n),b(n,0);
	cin>>a[0];
	if(a[0]==k) ans++,b[0]=1;
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]==k) ans++,b[i]=1;
		if(!k&&a[i-1]==1&&a[i]==1&&!b[i-1]) ans++,b[i]=1;
	}
	cout<<ans<<"\n";
	return 0;
}