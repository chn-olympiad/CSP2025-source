#include <bits/stdc++.h>
using namespace std;
int main(){
	fropen("number".in,"r","stdin");
	fropen("number".out,"w","stdout");
	string s,sl;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9')sl+=s[i];
	}
	for(int i=0;i<=sl.size();i++){
		for(int j=1;j<=sl.size();i++){
			if(sl[j-1]>sl[j])swap(sl[j-1],sl[j]);
		}
	}for(int i=0;i<=sl.size();i++){
		cout<<sl[i];
	}
return 0;
}
