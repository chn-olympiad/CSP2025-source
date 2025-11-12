#include <bits/stdc++.h>//Íê³É 
using namespace std;
const int N =1e6;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int q=1;
	for(int i=0;i<s.length();i++)
	{
		if(int(s[i])<97||int(s[i])>122)
		{
			a[q]=s[i]-48;
			q++;	
		}
	}
	sort(a+1,a+q+1);//man 
	for(int i=q-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

