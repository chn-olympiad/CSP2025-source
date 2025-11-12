#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#define int long long
using namespace std;
map<string,string>s;
int n,q,sum;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[s1]=s2;
	}
	while(q--){
		string s1,s2;
		sum=0;
		cin>>s1>>s2;
		for(int i=0;i<=s1.size();i++){
			for(int j=i;j<s1.size();j++){
				if(s[s1.substr(i,j)]==s2.substr(i,j)) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
