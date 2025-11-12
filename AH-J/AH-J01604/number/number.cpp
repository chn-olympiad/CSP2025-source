#include<bits/stdc++.h>
using namespace std;
int s1[1000];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;

int d=0;

cin>>s;
int g=s.size();
for(int i=0;i<=g;i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			s1[d]=s[i]-48;
			d++;}
}
sort(s1,s1+d,cmp);
for(int i=0;i<d;i++)
{
   cout<<s1[i];}
   return 0;
}
