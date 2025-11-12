#include<bits/stdc++.h>
using namespace std;
int jml[500086];
int main(){
	freopen("xor1.in","r",stdin);
	freopen("ans3.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>jml[i];
		if(k^jml[i]>ans)ans=(k^jml[i]);
	}
	cout<<ans;
	return 0;
}