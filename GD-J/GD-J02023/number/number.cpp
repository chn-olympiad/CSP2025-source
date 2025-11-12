#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
char a[N],b[N];
int num,n;
bool cmp(char xx,char yy)
{
	return xx>yy;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	n=strlen(a);
	for(int i=0;i<n;i++)
	{
		if('0'<=a[i] and a[i]<='9')
		{
			b[num]=a[i];
			num++;
		}
	}
	sort(b,b+num,cmp);
	printf("%s",b);
 	return 0;
} 
