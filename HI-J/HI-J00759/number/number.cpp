#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	char a[100001];
	cin>>s;
	int n=s.size();
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[k]=s[i];
			k++;
			
		}
	}
	
for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(a[j]<a[i])
			swap(a[i],a[j]);
		 } 
	}
	for(int i=k-1;i>=0;i--)
		cout<<a[i];
	
	fclose(stdin);
	fclose(stdout);
}
