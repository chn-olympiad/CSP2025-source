#include<bits/stdc++.h>
using namespace std;
bool sss(int x,int c){
    return 	x>c;
}
int qqq(string ss){
    return ss.size();	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n="";
	string s;
	getline(cin,s);
	int aa=qqq(s);
	for(int i=0; i<aa; i++){
		if(s[i]>='0' && s[i]<='9'){
			n+=s[i];
		}
		
	}
	sort(n.begin(),n.end(),sss);
	cout<<n;
	return 0;
}
