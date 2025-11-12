#include<bits/stdc++.h>
using namespace std;
string a;
int size=0,b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[++size]=a[i]-'0';
		}
	}
	sort(b+1,b+1+size);
	if(b[size]==0)printf("0");
	else
	{
		for(int i=size;i>=1;i--)
		{
			printf("%d",b[i]);
		}
	}
	
	return 0;
}
