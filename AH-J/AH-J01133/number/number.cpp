#include<bits/stdc++.h>
using namespace std;
char ch;
long long a[19];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch){
		if(ch>='0'&&ch<='9')a[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0)for(int j=1;j<=a[i];j++)cout<<i;
	}
}
