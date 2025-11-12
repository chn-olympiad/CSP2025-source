#include<bits/stdc++.h> 
using namespace std;
int main(){
//	freopen("number1.in","r",stdin);
//	freopen("number1.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long i=0,b=0;
	int c[100015];
	while(a[i]!='\0')
	{
		for(char j='0';j<='9';j++)
		{
			if(a[i]==j)
			{
				c[b]=a[i]-48;
				b++;
			}
		}
		i++;
	}
	for(long long l=0;l<b;l++)
	{
		for(long long p=l+1;p<b;p++)
		{
			if(c[l]<c[p])
			{
				long long d=c[l];
				c[l]=c[p];
				c[p]=d;
			}
		}
	}
	for(long long l=0;l<b;l++)
	{
		cout<<c[l];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
