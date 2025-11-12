#include<bits/stdc++.h>
using namespace std;
string p,s;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='9'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='8'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='7'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='6'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='5'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='4'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='3'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='2'){
			p+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(s[i]=='1'){
			p+=s[i];
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			p+=s[i];
		}
	}
	cout<<p;
	return 0;
} 
