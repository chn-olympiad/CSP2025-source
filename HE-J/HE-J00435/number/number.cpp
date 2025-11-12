#include<bits/stdc++.h> 
using namespace std;
char c[1000005];
int i,a[11];
int main(){
	freopen("number.in","r",stdin);
	 freopen("number.out","w",stdout);
	while(cin>>c[i])
	{i++;
	}
	for(int j=0;j<i;j++)
	{
		if(c[j]>47&&c[j]<58)
		a[c[j]-48]++;
	}
	for(int j=9;j>=0;j--)
	{
		while(a[j]--)
		{
			cout<<j;
		}
	}
	return 0;
}
