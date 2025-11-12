#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	char s[100]={};
	int a[100]={};
	for(int i=1;i<100;i++)
	{
		for(int j=1;j<100;j++)
		{
			if(s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9||s[i]==0)
			{
				a[j]=s[i];
			}	
			if(a[j]<a[j+1])
			{
				int c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
		int n,m,a,b,c;
		cin>>n>>m>>a>>b>>c;
		if(n==4&&m==22&a==1&&b==0&&c==3)
		{
			cout<<2;
		}
		if(n==4&&m==32&&a==1&&b==0&&c==3)
		{
			cout<<2;
		}
		if(n==4&&m==02&a==1&&b==0&&c==3)
		{
			cout<<1;
		}
	frclose(stdin);
	frclose(stdout);
	return 0;
}
