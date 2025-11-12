#include<bits/stdc++.h>
using namespace std;
char sr[1000000+5];
int pds[1000000+5];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sr;
	int s=strlen(sr),q;
	for(int i=0;i<s;i++)
	{
		if(sr[i]>='0' and sr[i]<='9')
		{
			q++;
			pds[q]=sr[i]-'0';
		}
	}
	sort(pds+1,pds+q+1);
	for(int i=q;i>=1;i--)
	{
		cout<<pds[i];
	}
	return 0;
} 