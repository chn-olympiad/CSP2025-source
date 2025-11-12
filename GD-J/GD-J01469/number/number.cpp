#include<bits/stdc++.h>
using namespace std;
string s;
int number[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]<='9'&&s[i]>='0') number[int(s[i]-'0')]++;
	for(int i=9;i>=0;i--) if(number[i]) while(number[i]--) cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

