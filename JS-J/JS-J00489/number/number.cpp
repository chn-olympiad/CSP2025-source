#include<bits/stdc++.h>
using namespace std;
int a[15];
string s,ans="";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
//			cout<<s[i]-'0';
		}
	}
	for(int i=9;i>=0;i--){
		char ch=char(i+'0');
		for(int j=1;j<=a[i];j++){
			cout<<ch;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
