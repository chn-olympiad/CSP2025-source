#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	freopen("number.in.txt","r",stdin);
	freopen("number.out.txt","w",stdout);
	string s;
	cin>>s;
	int n,c=0;
	n=s.size();
	char b[n];
	for(int i=0;i<n;i++)
		if(s[i]>=48&&s[i]<=57)  
		{
			b[c]=s[i];
			c++;
		}
	for(int i=1;i<c-1;i++) for(int j=0;j<c-i;j++) if(b[j]<b[j+1]) swap(b[j],b[j+i]);
	for(int i=0;i<c;i++) cout<<b[i];
	return 0;
}