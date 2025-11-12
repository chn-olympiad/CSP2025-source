//GZ-S00420中天中学赖小远 
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1,j;i<=n;i++){
		cin>>j;
		if(j==0)k++;
	}
	if(n-k<m)cout<<0;
	else{
	
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	
	}
	return 0;
}
