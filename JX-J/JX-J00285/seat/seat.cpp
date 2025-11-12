#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10];
	cin>>s;
	int q=0;
	while(s[q])
	{
		if(s[q]>='0'&&s[q]<='9')
		a[s[q]-0]++;
		q++;
		if(q==s.size())
		break;
	}
	for(int i=9;i>=0;i++)
	{
		if(a[i]!=0)
		for(int j=1;j<=a[i];j++)
		cout<<i;
	}
	
return 0;
}
