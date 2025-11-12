#include<bits/stdc++.h>
using namespace std;

char a[1000005],ans[1000005];

bool cmp(char p,char q)
{
	return p>q; 
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int sum=strlen(a),j=1;
	for(int i=0;i<sum;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			ans[j]=a[i];
			j++;
		}
	}
	j--;
	sort(ans+1,ans+j+1,cmp);
	for(int i=1;i<=j;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
