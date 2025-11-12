#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

string s;
int cnt=0;
int a[N]; 

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	int n=s.size();
	
	for(int i=1;i<=n;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			cnt++;
			a[cnt]=(int)(s[i]-'0');
//			cout<<a[cnt]<<endl;
		}
	}
	
	sort(a+1,a+1+cnt,cmp);
	
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	
	return 0;
 } 