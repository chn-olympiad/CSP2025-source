//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int p;
bool cmp(char y,char x)
{
	return y>x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			p+=1;
			a[p]=s[i];
		}
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++) cout<<a[i];
	return 0;
} 
