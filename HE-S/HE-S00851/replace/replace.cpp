#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[1000100][10];
string s1[1000100][10];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>s1[i][1]>>s1[i][2];
		cout<<0<<endl;
	}
}
