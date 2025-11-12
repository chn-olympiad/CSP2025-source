#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int sum=0;
	for(int i=0;i<s.size();i++)
		sum+=(s[i]-'0');
	if(sum<m)cout<<0;
	return 0;
}

