#include<bits/stdc++.h>
using namespace std;
string a;
int x1[19];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int s=a.size();
	for(int i=0;i<s;i++)if(a[i]<='9'&&a[i]>='0')x1[a[i]-'0']++;
	for(int i=9;i>=0;i--)while(x1[i]--)printf("%d",i);
	return 0;
}
