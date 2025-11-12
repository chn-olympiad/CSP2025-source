#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int s[110],n,m,a1,c=1,r=1;

bool cmp(int a,int b)
{
	if(a>b)return 1;
	return 0;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int x=n*m;

	for(int i=1;i<=x;i++)
	{
		cin>>s[i];
	}

	a1=s[1];

	sort(s+1,s+1+x,cmp);

	int cnt=1;
	for(int i=1;i<=x;i++)
	{
		if(s[i]==a1)cout<<c<<' '<<r;
		if(c%2==1){r++;cnt++;}
		else {r--,cnt++;}
		if(cnt==4){c++;cnt=1;}
	}

	return 0;
}

