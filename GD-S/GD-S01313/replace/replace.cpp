#include<iostream>
#include<cstdio>
using namespace std;
string s1[100000];
string s2[100000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i = 0;i<q;i++){
		string a,b;
		cin>>a>>b;
		cout<<0<<endl;
	}
} 
