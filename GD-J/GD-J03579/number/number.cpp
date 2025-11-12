#include<iostream>
#include<string>
using namespace std;
int numbers[10];
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++)if((s[i]>='0')&&(s[i]<='9'))numbers[s[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=0;j<numbers[i];j++)cout<<i;
	return 0;
}
