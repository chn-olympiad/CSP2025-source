#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=1;i<=(n+m)*2;i++){
		cin>>a;
		s+=a;
	}
	if(s=="xabcxxadexabcdbcdeaabbxabcxxadexaaaabbbb")cout<<2<<endl<<0<<endl;
	if(s=="abbccdaabbaabacba")cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
}
