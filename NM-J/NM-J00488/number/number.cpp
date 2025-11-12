#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string xx;
    for(int i=0;i<s.size();i++){
	    if(s[i]>='0'&&s[i]<='9'){
	    	xx += s[i];
		}
	}
	sort(xx.begin(),xx.end());
	string yy;
	for(int i=0;i<xx.size();i++){
		yy += xx[i];
	}
	reverse(yy.begin(),yy.end());
	for(int i=0;i<=xx.size();i++){
		cout<<yy[i];
	}
	return 0;
}
