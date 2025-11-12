#include <bits/stdc++.h>
using namespace std;

long long n,m,a[510],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans*=i;
	} 
	cout<<ans;
}
