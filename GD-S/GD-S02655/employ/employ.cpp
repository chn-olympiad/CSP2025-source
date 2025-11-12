#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans=1,a[10086];
string s; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i],ans=(ans*i)%998244353;
	for(int i=0;i<s.size();i++)x+=(s[i]=='1');
	if((x==s.size()&&n!=m)||(m==1))cout<<0;
	else cout<<ans;


	return 0;
}

