#include<iostream>
using namespace std;
string s;
int num[10]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') num[s[i]-'0']++;
	}
	
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
