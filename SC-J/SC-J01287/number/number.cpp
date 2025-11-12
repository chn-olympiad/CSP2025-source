#include<bits/stdc++.h>
using namespace std;
long long a[10]={0};
long long j=9;
string n="",s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=a[8]=a[9]=0;
	for(long long i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[int(s[i]-'0')]++;
	
	while(j>=0)
	{
		if(a[j]>0)
			n=n+char(j+'0'),a[j]--;
		else
			j--;
	}
	cout<<n;
	return 0;
} 