#include<bits/stdc++.h>
using namespace std;
int a[103],b[103];
bool cmd(int x,int y)
{
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n >>m;
	int zong=n*m;
	for(int i=1;i<=zong;i++)
	{
		cin >>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+zong+1,cmd);
	int pm;
	for(int i=1;i<=zong;i++)
	{
		if(a[1]==b[i])
		{
			pm=i;
			break;
		}
	}
	int c,r;
	c=pm/n;
	if(pm%n!=0) c++;
	r=pm-(c-1)*n;
	if(c%2==0) r=n-r+1;
	cout <<c <<" " <<r;
	return 0;
}
