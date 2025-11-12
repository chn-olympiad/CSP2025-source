#include<bits/stdc++.h>
#define ll long long
#define str string
#define I return
#define Will 0
#define AK ;
using namespace std;
str s;
ll a[15];
bool ok;
void setup()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int main()
{	
	setup();
	cin>>s;
	for(auto i:s)
		if(isdigit(i))a[int(i-'0')]++;
	for(int i=9;i>=0;i--)
	{
		if(i>=1&&a[i])ok=true;
		if(i==0&&!ok)
		{
			cout<<0;
			break;
		}
		while(a[i]--)
			cout<<i;
	}
	I Will AK	
} 
