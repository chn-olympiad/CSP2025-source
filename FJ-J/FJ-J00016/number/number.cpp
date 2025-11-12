#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	char h[l];
	for (int i=0;i<l;i++) h[i]=s[i];
	sort(h,h+l);
	for (int i=l-1;i>=0;i--)
	{
		if(h[i]>='0' && h[i]<='9') cout<<h[i];
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
