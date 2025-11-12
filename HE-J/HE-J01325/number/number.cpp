#include<bits/stdc++.h>
using namespace std;
int n[100000005],c;
string s;
int main(){
//	feropen("number.in","w",stdin);
//	feropen("number.out","r",stdout);
	cin>>s;
	for(int i=1;sies(s);i++){
		if(s[i]=='1'&&s[i]=='2'&&s[i]=='3'&&s[i]=='4'&&s[i]=='5'&&s[i]=='6'&&s[i]=='7'&&s[i]=='8'&&s[i]=='9'){
			n[i]=s[i];c++;
		}
	}
	for(int i=1;i<=c;i++){
		cout<<n[i]; 
	}
	return 0;
}
