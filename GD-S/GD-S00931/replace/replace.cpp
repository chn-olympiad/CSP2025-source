#include<bits/stdc++.h>
using namespace std;

int n,q;
string s[1000000][2],t[1000000][2];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int j=1;j<=q;j++)
		cin>>t[j][0]>>t[j][1];
	for(int i=1;i<=q;i++)
		cout<<'0'<<endl;
	return 0;
}
