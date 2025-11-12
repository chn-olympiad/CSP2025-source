#include<bits/stdc++.h>
using namespace std;
char str;
string ans;
map<char,int> m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&str)){
		if(str>='0'&&str<='9') m[str]++;
		if(str=='P') break;
	}
	map<char,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		for(int i=1;i<=it->second;i++) ans+=char(it->first);
	}
	for(int i=ans.size()-1;i>=0;i--) printf("%c",ans[i]);
	
	return 0;
}
//8:47Completed 
