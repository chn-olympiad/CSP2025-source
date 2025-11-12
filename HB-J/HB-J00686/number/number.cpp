#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100000];int a[1000000]={0},sum=0,b[10],i=0;
	cin>>s;
	while(s[i]!='\0')
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[sum]=s[i]-48;
			sum++;
		}
		i++;
	}
	for(int i=0;i<sum;i++){
		b[a[i]]+=1;}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<b[i];j++){
			cout<<i;}
	}
	fclose(stdin);
	fclose(stdout);
}
