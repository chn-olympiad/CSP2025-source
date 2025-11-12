#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[50009];
string s2[50009];
string t1[50009];
string t2[50009];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i = 1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i = 1;i<=q;i++){
		cout<<t1[i].length()-t2[i].length();
	}
	return 0;
}
