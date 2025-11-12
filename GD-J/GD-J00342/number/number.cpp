#include<bits/stdc++.h>
using namespace std;
int n,b[15];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')b[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i]--)printf("%d",i);
	}
	return 0;
}
