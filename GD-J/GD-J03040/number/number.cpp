#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
using namespace std;
const int N = 1e6+10;
string s,a[N];
//int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	int len=s.size(),len2=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[len2]=s[i];
			//cout<<a[len2]<<" ";
			len2++;
		}
	}
	sort(a+0,a+len2+1);
	for(int i=len2;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
