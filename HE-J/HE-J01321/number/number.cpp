#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string s;
int tmp[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')tmp[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=tmp[i];j++)cout<<i;
	return 0;
}
