#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
}
