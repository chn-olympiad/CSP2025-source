#include<bits/stdc++.h>
using namespace std;
int n,m;
string st;
int a[501];
long long sum=1;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	bool flag=false;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]=='0') flag=true;
	 } 
	if(flag==false){
		for(int i=n;i>=1;i--) 
		{
			sum=(sum*i)%mod;
		}
		cout<<sum;
	}
	return 0;
}
