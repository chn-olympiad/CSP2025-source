#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(int argc,char** argv){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s("howlong???oh...");
	cin>>s;
	unsigned long long int ans=0;
	vector<unsigned short> numbers;
	for(unsigned long long int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9')
			numbers.push_back(s[i]-'0');
	bool isZero=true;
	for(unsigned short i=9;i>0;i--)
		for(unsigned long long int j=0;j<numbers.size();j++)
			if(numbers[j]==i){
				isZero=false;
				cout<<i;
			}
	if(isZero){
		cout<<0;
	}else{
		for(unsigned long long int i=0;i<numbers.size();i++)
			if(!numbers[i])
				cout<<0;
	}
}