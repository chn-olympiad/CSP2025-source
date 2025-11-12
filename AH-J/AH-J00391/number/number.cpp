#include<bits/stdc++.h>
using namespace std;
string s,w;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			w+=s[i];
	    }
    }
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());
    cout<<w;
	return 0;
}
