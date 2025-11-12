#include <bits/stdc++.h>
using namespace std;
string s,c;char n;
int a[1000006],q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    int len=s.size();
    for (int i=0;i<len;i++)
    {
    	if (s[i]>='0'&&s[i]<='9')
    	{
    		a[q]=s[i]-'0';
    		q++;
		}
	}
	sort(a,a+q,greater<int>());
	for (int i=0;i<q;i++)
	{
		n=a[i]+'0';
		c=c+n;
	}
	cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
