#include<bits/stdc++.h>
using namespace std;
string x;
long long a[1000005],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	int n=x.size();
	for(int i=0;i<n;i++)
	{
		if(x[i]>='0'&&x[i]<='9')
		{
			k++;
			a[k]=x[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>0;i--)
	{
		printf("%lld",a[i]);
	}
	return 0;
} 
