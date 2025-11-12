#include<bits/stdc++.h>
using namespace std;
char a[1000001];
char b[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	int c=x.size();
	for(int i=0;i<c;i++)
	{
		if(int(x[i])>=49&&int(x[i])<=57)
		{
			a[i]=x[i];
		}
	}
	int y=0;
	for(int k=0;k<c;k++)
	{
		if(a[k]>0)
		{
			b[y]+=a[k];
			y+=1;
		}
	}
	for(int i=0;i<c;i++)
		cout<<b[i];
}
