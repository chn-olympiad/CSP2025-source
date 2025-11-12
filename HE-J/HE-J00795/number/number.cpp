#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int len=s.size();
	int a[10001];
	int q=0;
	for(int i=0;i<len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			s[i];
		}else continue;
		q=s[i];
		if(s[i]>q){
			cout<<s[i];
			s[i]=q;
		}
		cout<<s[i]<<" "; 
	}
	return 0;
} 
