#include<bits/stdc++.h>
using namespace std;
string s,s2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]=='9'){
			s2+=s[i];
			s[i]='a';
		}
	}

	for(int i=0;i<a;i++){
		if(s[i]=='8'){
			s2+=s[i];
			s[i]='a';
		}
	}
	for(int i=0;i<a;i++){
		if(s[i]=='7'){
			s2+=s[i];
			s[i]='a';
		}
	}
	for(int i=0;i<a;i++){
		if(s[i]=='6'){
			s2+=s[i];
			s[i]='a';
		}
	}
	for(int i=0;i<a;i++){
		if(s[i]=='5'){
			s2+=s[i];
			s[i]='a';
		}
	}
	for(int i=0;i<a;i++){
		if(s[i]=='4'){
			s2+=s[i];
			s[i]='a';
		}
	}
	for(int i=0;i<a;i++){
		if(s[i]=='3'){
			s2+=s[i];
			s[i]='a';
		}
	}	
	for(int i=0;i<a;i++){
		if(s[i]=='2'){
			s2+=s[i];
			s[i]='a';
		}
	}	
	for(int i=0;i<a;i++){
		if(s[i]=='1'){
			s2+=s[i];
			s[i]='a';
		}
	}
	for(int i=0;i<a;i++){
		if(s[i]=='0'){
			s2+=s[i];
			s[i]='a';
		}
	}	
	cout<<s2<<endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;					
}
