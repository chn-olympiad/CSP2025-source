#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	//freopen("number1.in","r",stdin);
	//freopen("number.out","w",stdout);
	//ios::sync_with_stdio(False);
	string s,n;
	//getline(cin,s);
	cin>>s;
	int r=s.size();//1
	for(int q=1;q<=r;q++)
	{
		if(s[q]<='65'&&s[q]>='92')
		{
			n[q]=s[q];
		}
	}
	int i=0,u=n.size();
	for(int i=u;i>=1;i--)
	{
		cout<<n[i];
	}
	return 0;
}
