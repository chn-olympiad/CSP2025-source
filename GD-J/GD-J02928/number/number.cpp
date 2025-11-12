#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char c;
    string str="";
    while(cin>>c){
    	if(isdigit(c))
    		str+=c;
	}
	sort(str.begin(),str.end(),greater<char>());
	cout<<str;
	return 0;
}
