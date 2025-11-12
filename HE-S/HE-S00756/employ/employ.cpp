#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],sum=0,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			sum++;
		}
	}
	for(int i=1;i<=sum;i++){
		ans=ans*i;
	}
	cout<<ans%998244353;
	return 0;
}
