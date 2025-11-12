#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string str1,str2;
map<string,string>M;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str1>>str2;
		M[str1]=str2;
	}
	while(q--){
		ans=0;
		cin>>str1>>str2;
		if(str1.size()!=str2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<str1.size();i++){
			for(int j=i+1;j<str1.size();j++){
				if(M.count(str1.substr(i,j-i+1))&&(str1.substr(0,i)+M[str1.substr(i,j-i+1)]+str1.substr(j+1,str1.size()-j))==str2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
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
