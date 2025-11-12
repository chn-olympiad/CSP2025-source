#include<bits/stdc++.h>
using namespace std;
int num[150];
char n;
string x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<int(x.length());i++)
	{
		if(x[i]>='0'&&x[i]<='9')num[x[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]>0){
		cout<<i;
		num[i]--;
		}
	}
	return 0;
}
