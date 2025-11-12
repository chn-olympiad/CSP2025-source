#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int n,q;
string s,t,tmp,l,r;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		mp[s]=t;
	}
	while(q--){
		cin>>s>>t;
		int cnt=0;
		for(int i=0;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				tmp=s.substr(i,j-i+1);
				tmp=mp[tmp];
				l=s.substr(0,i);
				r=s.substr(j+1,s.size()-1-j);
				l=l+tmp+r;
				if(l==t){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
