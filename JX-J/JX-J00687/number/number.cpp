#include<bits/stdc++.h>
using namespace std;
char a[100001];
int b[100001],c[100001];
int i=0,ans,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a[i])
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[i]=(int)a[i]-48;c[i]=b[i];
			//cout<<b[i];
		}
		i++;
		sum=i;
	}
	for(int ans=0;ans<sum;ans++)
	{
		for(int j=ans+1;j<sum;j++)
		{
			//cout<<b[ans];
			if(c[ans]<c[j])
			{
				//cout<<c[ans];
				swap(c[ans],c[j]);
				//cout<<c[ans];
			}		
		}
		
	}
	for(int ans=0;ans<sum;ans++)
	{
		cout<<c[ans];
	}
	return 0;
}
