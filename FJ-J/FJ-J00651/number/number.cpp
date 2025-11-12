#include<iostream>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[int(s[i]-'0')]++;
	for(int j=9;j>=0;j--) for(int b=0;b<a[j];b++) cout<<j;
	cout<<endl;
	return 0;
}
