#include<bits/stdc++.h>
using namespace std;
int mynum[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int len=s.size();
	for(int i=0;i<=len;i++)
	  if(s[i]>='0' && s[i]<='9') 
		mynum[int(s[i]-'0')]++;
	for(int k=9;k>=0;k--)
	{
		while(mynum[k]>0)
		{
			cout<<k;
			mynum[k]--;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}