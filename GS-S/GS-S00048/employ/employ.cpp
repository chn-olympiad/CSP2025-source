#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans;
	for(int i=1;i<=n;i++){
		ans=ans*i;
	}cout<<ans;
	return 0;
}
