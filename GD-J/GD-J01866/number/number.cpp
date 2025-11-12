#include<bits/stdc++.h>
using namespace std;
#define P9
#ifdef P9
	inline void su(){freopen("number.in","r",stdin);freopen("number.out","w",stdout);}
#elif
	 inline void su(){}
#endif
int main(){
	su();
	string s,g;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')g+=s[i];
	}
	sort(g.begin(),g.end());
	for(int i=g.size()-1;i>=0;i--){
		cout<<g[i];
	}
	return 0;
}

