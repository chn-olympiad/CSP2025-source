#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
	cin>>s;
	int a=s.size();
	int b[a];
	int t;
	for(int i=0;i<a;i++){
		if(s[i]=='1'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='2'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='3'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='4'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='5'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='6'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='7'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='8'){
			b[i]=s[i]-'0';
			t++;
		}
		if(s[i]=='9'){
			b[i]=s[i]-'0';
			t++;
		}
	}
	int g[t];
	sort(b,b+a); 
	for(int i=0;i<a;i++){
		if(b[i]!=0){
			g[i]=b[i];
		}
	}
	for(int i=0;i<t;i++){
		cout<<g[i];
	}
	return 0;
} 
