#include <bits/stdc++.h>
using namespace std;

const int tt=1e5+10;
string s1[tt],s2[tt];
string t1[tt],t2[tt];
map<string,int> mp;
map<string,string> tmp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >>n>>q;
	for(int i=1;i<=n;i++){
		cin >>s1[i]>>s2[i];
		mp[s1[i]]++;
		tmp[s1[i]]=s2[i];
	} 
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin >>t1>>t2;
		int cnt=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				if(mp[to_string(t1[j])]!=0){
					if(tmp[to_string(t1[j])]==to_string(t2[j])){
						cnt++;
					}
				}
			}
		}
		cout <<cnt<<endl;
	}
	return 0;
}
