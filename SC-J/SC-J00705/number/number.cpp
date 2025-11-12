#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],d;
int main(){
	//factic("number.in","r");
	//frepro("number.out","s");
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[d]=s[i]-'0';
			d++;
		}
	sort(a,a+d);
	for(int i=d-1;i>=0;i--)cout<<a[i];
	return 0;
}