#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='z'&&s[i]>='a'){
			s.erase(i,1);
			i--;
		}
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
