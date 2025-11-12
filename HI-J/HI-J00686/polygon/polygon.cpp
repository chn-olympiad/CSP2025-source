#include <bits/stdc++.h>
using namespace std;
int lk(int x,int y)
{
	if(x+y>max(x,y)*2) return 1;
	return 0;
}
int n,a[5001],num=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(lk(a[1],a[2])) num++;
	if(lk(a[1],a[3])) num++;
	if(lk(a[2],a[3])) num++;
	return 0;
}

