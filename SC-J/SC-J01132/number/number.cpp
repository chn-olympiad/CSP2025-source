#include<iostream>
#include<cstring>
using namespace std;
char a;
int num[105];
//int ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a)
	{
		if((a<'0')||(a>'9'))
		continue;
		num[a-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]!=0)
		{
		//	ans=ans*10+i;
		    cout<<i;
			num[i]--;
		}
	}
	//cout<<ans;
	return 0;
}