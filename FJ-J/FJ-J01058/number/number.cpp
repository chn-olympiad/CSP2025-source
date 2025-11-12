#include <bits/stdc++.h>
using namespace std;

bool cmp(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ch=" ";
	int tot=0;
	cin>>s;
	for(char c:s){
		if(isdigit(c)){
			ch.push_back(c);
			tot++;
		}
	}
	sort(&ch[1],&ch[tot+1],cmp);
	cout<<string(&ch[1],&ch[tot+1])<<endl;
	return 0;
}
