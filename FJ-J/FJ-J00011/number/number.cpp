#include<bits/stdc++.h>
using namespace std;
char ch[(int)1e6+5];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	string o;
	cin>>s;
	int under=1;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')ch[under++]=s[i];
	}
	sort(ch+1,ch+under,greater<char>());
	for(int i=1;i<under;i++){
		cout<<ch[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
