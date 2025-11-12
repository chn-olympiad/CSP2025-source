#include<bits/stdc++.h>
using namespace std;
long long n,m,s,i,c[1009],ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n-2;i++)ans+=i;
	cout<<ans;
}
