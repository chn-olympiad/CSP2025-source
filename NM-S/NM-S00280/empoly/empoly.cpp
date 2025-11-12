#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[10000000],ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
		ans+=b[i];
	}cout<<ans;
	return 0;
}
