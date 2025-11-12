#include <bits/stdc++.h>
int isshu(int x)
{
	if(x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9'||x=='0')
	{
		return 0;
	}
}
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
long long m[1000000];
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	long long sum=0;
	cin>>a;
	int b=getline(a);
	for(long long i=0;i<1;i++)
	{
		if(isshu(a[i])==0)
		{
			sum++;
			m[sum]=a[i]-48;
		}
	}
	sort(m,m+sum,cmp);
	for(int i=1;i<=sum;i++)
	{
		cout<<m[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
