#include<iostream>
using namespace std;
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	bool bj=0;
	cin>>s;
	for(const auto& i:s)
	{
		if(i>'0'&&i<='9')
		{
			num[i-'0']++;
			bj=1;
		}
		if(i=='0')num[0]++;
	}
	if(bj=false){
		cout<<0;
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]>0)
		{
			cout<<i;
			num[i]--;
		}
	}
}
