#include<bits/stdc++.h>
using namespace std;
string s;
long long n,c[13];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='9'){
			cout<<9;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='8'){
			cout<<8;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='7'){
			cout<<7;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='6'){
			cout<<6;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='5'){
			cout<<5;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='4'){
			cout<<4;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='3'){
			cout<<3;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='2'){
			cout<<2;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='1'){
			cout<<1;
		}
	}for(long long i=0;i<s.size();i++){
		if(s[i]=='0'){
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

