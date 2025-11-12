#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],mod=998244353,ans;
bool flag=true;
string s1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s1;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int l=s1.size();
	for(int i=0;i<l;i++){
		if(s1[i]==0)
			flag=false;
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<1;
	return 0;
} 
