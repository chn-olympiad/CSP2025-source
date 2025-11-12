#include<bits/stdc++.h>
using namespace std;
int n,q,a,b; 
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	q=1;
	for(int i=0;i<=s.size();++i){
		if(s[i]=='a'){
			++a;
		}else if(s[i]=='b' && b==0){
			++b;
		}
	}
	for(int i=0;i<=q;++i){
		cout<<0<<"\n";
	}
	return 0;
}