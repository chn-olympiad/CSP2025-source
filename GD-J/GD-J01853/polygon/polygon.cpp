#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100011111],ans,cnt,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+1+n);
	cnt=a[n];
	cnt*=2;
	for(int i=1;i<=n;i++)	
	{
		if(ans>cnt)
		{
			printf("%d",1);
			break;
		}
		else
		{
			printf("%d",0);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
//Æ­·Ö£¬¸øµã°É£¡£¡£¡ 
}
