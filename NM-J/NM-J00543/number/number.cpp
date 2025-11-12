#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b){
    return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0;
	cin>>s;
	char ch[105];
	for(int i=0;i<s.size();i++){
	    if(isdigit(s[i])==1){
	    	ch[a]=s[i];
	    	a++;
		}
	}
	int b[105];
	for(int i=0;i<a;i++){
		b[i]=ch[i]-'0';
	}
	sort(b,b+a,com);
	for(int i=0;i<a;i++){
		cout<<b[i];
	}
    return 0;
}
