#include<bits/stdc++.h>
using namespace std;
const int N=505;
string str;
int n,m,ans=1;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=2;i<=m;i++)
		ans=(ans*i)%998244353;
	cout<<ans<<endl;
	return 0;
} 
