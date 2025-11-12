#include<bits/stdc++.h>
using namespace std;
int s[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+3);
	if(s[0]+s[1]>s[2]) cout<<1;
	else cout<<0; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
