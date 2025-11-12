#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int no=1;
//	cout<<s.size();
	for(int i=0;i<s.size();i++)
	{
//		cout<<1<<'\n';
		if(s[i]>='0'&&s[i]<='9')
		{
			b[no]=(s[i]-48);
			no++;
		}
	}
	no--;
	sort(b+1,b+1+no);
	for(int i=no;i>=1;i--)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
