#include <bits/stdc++.h>
using namespace std;
string s;
int maxx;
int shu;
int q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		maxx=-1;
		for(int j=0;j<s.size();j++){
			if(s[j]>='0'&&s[j]<='9'){
				if(maxx<s[j]-'0'){
					maxx=s[j]-'0';
					q=j;
				}
			}
		}
		s[q]='a';
		if(maxx>=0){
			shu=shu*10+maxx;
		}
	}
	cout<<shu;
	return 0;
}
