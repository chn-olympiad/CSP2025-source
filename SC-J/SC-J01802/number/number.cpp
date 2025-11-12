#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000005],t;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t++;
			b[t]=s[i]-'0';
		}
	}
	sort(b+1,b+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
	     cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}