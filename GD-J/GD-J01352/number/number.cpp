#include<bits/stdc++.h>
using namespace std;
string x;
int s[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<x.size();i++)
		if('0'<=x[i]&&x[i]<='9')
			s[x[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=s[i];j++)
			cout<<i;
	cout<<"\n";
	return 0;
}
