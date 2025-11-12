#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	string num;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9') num+=str[i];
	}
	sort(num.begin(),num.end(),cmp);
	cout<<num<<endl;
	return 0;
} 
