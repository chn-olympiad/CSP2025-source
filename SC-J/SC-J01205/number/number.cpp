#include<bits/stdc++.h>
using namespace std;
char s[1000010],x[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0,i;
	cin.getline(s,99999);
	for(i=0;i<=strlen(s);i++) 
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x[k]=s[i];
			k++;
		} 
	}
//	cout<<k<<endl; 
	sort(x,x+k);
	reverse(x,x+k);
	for(i=0;i<strlen(x);i++)
	{
		cout<<x[i]; 
	}
	return 0;
}