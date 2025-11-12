#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[10],c;
	for(int i=0;i<10;i++)
	b[i]=0;
	cin>>a;
	c=a.size();
	for(int i=0;i<c;i++)
	{
		if(a[i]=='1')
		b[1]++;
		if(a[i]=='2')
		b[2]++;
		if(a[i]=='3')
		b[3]++;
		if(a[i]=='4')
		b[4]++;
		if(a[i]=='5')
		b[5]++;
		if(a[i]=='6')
		b[6]++;
		if(a[i]=='7')
		b[7]++;
		if(a[i]=='8')
		b[8]++;
		if(a[i]=='9')
		b[9]++;
		if(a[i]=='0')
		b[0]++;
	}
	for(int i=9;i>=0;i--)
	for(int j=1;j<=b[i];j++)
	cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
