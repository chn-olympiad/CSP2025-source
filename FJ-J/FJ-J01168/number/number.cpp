#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int num[N];
bool cmp(int a,int b)
{
	if(a!=b) return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0,p=0;
	string ss;
	cin>>ss;
	for(int i=0;i<ss.size();i++)
	{
		if(ss[i]>='0'&&ss[i]<='9')
		{
			num[k++]=ss[i]-'0';
			p++;
		}
	}
	sort(num,num+p,cmp);
	for(int i=0;i<p;i++)
	{
		cout<<num[i];
	}
	return 0;
}
