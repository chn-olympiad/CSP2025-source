#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string s1,s2="";
	cin>>s1;
	int n=s1.size(),m=0;
	s1=" "+s1;
	for(int i=1;i<=n;i++)
		if('0'<=s1[i]&&s1[i]<='9')
			s2+=s1[i],m++;
	sort(s2.begin(),s2.end(),cmp);
	cout<<s2;
	return 0;
}

