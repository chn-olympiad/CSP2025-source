#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int v;
int num[N];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]>='0' && s[i]<='9')
			num[++v]=s[i]-48;
	sort(num+1,num+v+1,cmp);
	for(int i=1; i<=v; i++)
		cout<<num[i];
	return 0;
}
