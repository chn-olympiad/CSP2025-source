#include<bits/stdc++.h>
using namespace std;
string ss;
const int N=1e6+10;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	int aa=0;
	for(int i=0;i<ss.size();i++)
	{
		if(ss[i]>='0' && ss[i]<='9') 
		{
			
			a[aa]=(int)(ss[i]-'0');
			aa++;
		}
	}
	sort(a,a+aa);
	for(int i=aa-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
