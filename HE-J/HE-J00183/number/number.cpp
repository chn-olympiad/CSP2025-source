#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000050];
int sum=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[sum]=a[i]-'0';
			sum++;
		}
	}
	sort(b,b+sum,cmp);
	for(int i=0;i<sum;i++)
	{
		cout<<b[i];
	}
	return 0;
}
