#include<bits/stdc++.h>
using namespace std;
int record[1000005];
int main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int le=s.size();
	for(int i=0;i<le;i++)
	    if(s[i]>='0' && s[i]<='9')
	        record[++record[0]]=s[i]-'0';
	sort(record+1,record+1+record[0]);
	for(int i=record[0];i;i--)
		cout<<record[i];
	return 0;
}