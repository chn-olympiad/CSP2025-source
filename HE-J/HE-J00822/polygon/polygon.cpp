#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	int n,number,maxi=-9999,zong=0;
	cin>>n;
	int a[5005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(maxi<a[i]) maxi=a[i];
			number+=a[i];
		}
		if(number>maxi*2) zong++;
	}
	cout<<zong;
fclose(stdin);
fclose(stdout);
return 0;
}
