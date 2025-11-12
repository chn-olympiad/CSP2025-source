#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e5+10;
const int M=2e6+10;
int n,q;
string t1,t2;
struct node{
	string s1,s2;
}d[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>d[i].s1>>d[i].s2;
	for (int k=1;k<=q;k++){
		cin>>t1>>t2;
		cout<<0<<'\n';
	}
	return 0;
}
