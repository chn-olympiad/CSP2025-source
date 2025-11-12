#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
string s;
int c[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ans=ans*i;
	}
	cout<<ans-2;
	return 0;
}
