#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=1e6+5;
string st;
char ji[maxn];
int s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>st;
	int len=st.length();
	int meb=0;
	for(int i=0;i<len;i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			
			ji[meb]=st[i];
			meb++;
		}
	}
	sort(ji,ji+meb);
	for(int i=meb-1;i>=0;i--)
	{
		cout<<ji[i];
	}
	return 0;
}