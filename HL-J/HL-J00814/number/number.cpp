#include<bits/stdc++.h>
using namespace std;
int number[100001];
bool cmp(int a,int b){
return a>b;
}
int main(){
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]>='0'&&s[i]<='9')
	number[ans++]=s[i]-'0';
	sort(number,number+ans,cmp);
	for(int i=0;i<ans;i++)
	cout<<number[i];
	return 0;
}
