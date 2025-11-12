#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	map<string,string> pat;
	for(int i=0;i<n;i++){
		string s,s2;
		cin >> s >> s2;
		pat[s] = s2;
	}
	for(int i=0;i<q;i++){
		int a = 0;
		string s,s2;
		cin >> s >> s2;
		for(int j=0;j<s.size();j++){
			for(map<string,string>::iterator it=pat.begin();it!=pat.end();it++){
				if(j+it->first.size()>s.size())continue;
				string ats = s;
				bool f = true;
				for(int z=0;z<it->first.size();z++)if((it->first[z]==ats[z+j])){
					ats[z+j] = it->second[z];
				}else f=false;
				if(f&&ats==s2){
					a++;
					//cout << it->first << ' ' << it->second << endl; 
				}
			}
		}
		cout << a << endl;
	}
	return 0;
}