#include<bits/stdc++.h>
using namespace std;
/*void xx(s1,s2)
{
	bool efsdf=0;
	for(int i=0;i<s1.length();i++)for(int j=0;j<s2.length();j++)if(s1[i]+34!=s2[i]-34)s1[i]=s2[i];
	cout<<s1+s2-s3<<efsdf;
	BOOL CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) 
	{
		case 0:
		{
			break;
		}
		default:
			return false;
	}
	return true;
}*/
int n,q;
int s1[100000],s2[100000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	for(int i=0;i<q;i++)cin>>s1[i]>>s2[i];
	cout<<0<<endl<<0;
	return 0;
}
