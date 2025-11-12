#include<bits/stdc++.h>
using namespace std;
char b[10005];
int p;	
string a;
long long i;
bool cmp(char a,char b)
{
	return int(a) >= int(b);
}
void check(long long p)
{
	if(b[0]=='0')
	{
		cout<<0;
		return ;
	}
	else
	{
		for( int i=0;i<p;i++)
		{
			cout<<b[i];
		}
		return ;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a;
	int num=a.size();
	for(int i=0;i<num;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
		b[p]=a[i];
		p+=1;
	}
}
    sort(b,b+p,cmp);
       check(p);
	return 0;
	}
