#include<bits/stdc++.h>
using namespace std;
char a[1000006];
int n[1000006],qwe;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++)
		{
			if(a[i]>='0'&&a[i]<='9') 
				{
					qwe++;
					n[qwe]=a[i]-'0';
				}
		}
	for(int i=1;i<=qwe;i++) 
		for(int j=i+1;j<=qwe;j++) 
			if(n[i]<=n[j]) swap(n[i],n[j]);
	for(int i=1;i<=qwe;i++) 
		cout<<n[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
