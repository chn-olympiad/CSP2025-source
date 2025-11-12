#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0,c=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'||'1'<=s[i]&&s[i]<='0')a++;
	}
	int b[a];
	a=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'||'1'<=s[i]&&s[i]<='0'){
			b[a]=s[i];
			a++;
		}
	}
	a+=1;
	sort(b,b+a);
	for(int i=a-1;i>=0;i--){
		c=c*10+b[i];
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
