#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int nub[12]={};
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			nub[s[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		if(nub[i]>0){
			for(int j=0;j<=nub[i];j++)cout<<i;
		}
	}
}