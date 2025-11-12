#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],h=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++) if(s[i]<='9'&&s[i]>='0') a[h]=int(s[i]-48),h++;
	sort(a,a+h);
	for(int i=h-1;i>=0;i--)	cout<<a[i];
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
