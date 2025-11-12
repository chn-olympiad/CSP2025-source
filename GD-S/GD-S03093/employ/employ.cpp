#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=1;
int n,m,a,ss;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a==0)ss++;
	}
	for(int i=n-ss,j=1;j<=m;j++,i--)
		ans=ans*i/j;
	cout<<ans;
	return 0;
}
