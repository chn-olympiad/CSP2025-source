#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int ljh=1e6+9;//2023.26.刘嘉贺 
string s;
long long a[ljh],l;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin>>s;
	l=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a+1,a+l);
	for(int i=l-1;i>=1;i--)
	    cout<<a[i];
	return 0;
} 

//分享趣事：本来打算给样例四写一个比较用的代码，但是太长怕string爆掉，还是不写了吧 
