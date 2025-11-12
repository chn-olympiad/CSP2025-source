#include <bits/stdc++.h>
using namespace std;
int f[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a; cin>>a;
	int cnt=1,sum=a.size();
	for(int i=0;i<sum;i++)
		if(a[i]>='0'&&a[i]<='9') f[cnt++]=a[i]-'0';
	cnt--;
	sort(f+1,f+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		printf("%d",f[i]);
	printf("\n");
	return 0;
}
