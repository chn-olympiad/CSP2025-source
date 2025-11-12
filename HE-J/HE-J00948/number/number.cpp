#include<bits/stdc++.h>
using namespace std;
char s;
int a[1000010],b,c,o,i;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	
	while(cin>>s)
	{
		i++;
//		cout<<s;
		if (s<='9'&&s>='0')
		{
			a[o++]=s-'0';
//			cout<<a[o-1]<<endl;
			
			
		}
	}//cout<<o<<endl; 
	sort(a,a+o,cmp);
	for (int i=0;i<o;i++)
	{
//		cout<<a[i];
		printf("%d",a[i]);
	}
	return 0;
	fclose(stdin);fclose(stdout);
} 
