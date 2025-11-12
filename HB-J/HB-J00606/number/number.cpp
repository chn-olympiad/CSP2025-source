#include<bits/stdc++.h>
using namespace std;
string a;
int lenb,k;
int b[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	cin>>a;
	int lena=a.size();
	
	for(int i=0;i<lena;i++)
	{
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
		{
			b[k]=a[i]-'0';
			lenb++;
			k++;
		}
	}	
	sort(b,b+lenb,cmp);
	for(int j=0;j<lenb;j++)
	{
		cout<<b[j];
	}
	
	return 0;
	
}
