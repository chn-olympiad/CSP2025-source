#include<bits/stdc++.h> 
using namespace std;
string cr;
int a[15],i,k;
int main ()
{
freopen(" number.in","r",stdin);
freopen("number.out","w",stdout);
	cin>>cr;
	long long ch=cr.length();
	for(i=0;i<ch;i++)
	{
		if(cr[i]>='0'&&cr[i]<='9')
		{k=cr[i]-'0';
		a[k]++;
		 } 
	}
	for(i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	
	return 0;
}
