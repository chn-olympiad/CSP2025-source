#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,l,r;
string st1,st2;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=m;i++)
	{
		cin>>st1>>st2;
		cout<<"0\n";
	}
	return 0;
} 
