#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
long long num[1000001],len=0;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
			if(s[i]-'0'==9) cout<<9;
		else num[++len]=s[i]-'0';
	}
	sort(num+1,num+len+1,cmp);
	if(num[1]==0){
		cout<<0;return 0;
	} 
	for(int i=1;i<=len;i++){
		cout<<num[i];
	}
	return 0;
} 
