#include<bits/stdc++.h>
using namespace std;
int b[1000005],j=0,l;
int smap(int x,int y)
{
	return x>y;
}
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	cin>>s;
	l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			b[j]=s[i]-'0';
		}
	}
	sort(b+1,b+j+1,smap);
	for(int i=1;i<=j;i++)
	{
		cout<<b[i];
	}
	fclose(stdin);fclose(stdout); 
	return 0;
}

