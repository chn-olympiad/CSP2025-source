#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++)
	if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0')
	{
	b[k]=a[i]-'0';
	k++;
	}
	sort(b,b+k);
	for(int i=k-1;i>=0;i--)printf("%d",b[i]);
	
	return 0;
}
