#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

string a;
int num[100005],cnt=0;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0' && a[i]<='9'){num[cnt]=a[i]-'0';cnt++;}
	}

	sort(num,num+cnt);

	for(int i=cnt-1;i>=0;i--)cout<<num[i];

	return 0;
}
