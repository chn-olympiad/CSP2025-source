#include<bits/stdc++.h>
using namespace std;
int b[10],num;
int main(){
freopen("number.in","r",stdin);
freopen("naumber.out","w",stdout);
string a;
cin>>a;
num=a.size();
for(int i=0;i<num;i++)
{
	if(a[i]>='0'&&a[i]<='9')
	{
		b[int(a[i]-'0')]++;
	}
}
for(int i=9;i>=0;i--)
{
	while(b[i]>=0)
	{
		cout<<i;
		b[i]--;
	}
}
return 0;
}
