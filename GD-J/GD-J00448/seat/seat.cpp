#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010],num,lie,hang;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			lie=(i-1)/n+1;
			if(lie%2==1)
			{
				hang=(i-1)%n+1;
			}
			else
			{
				hang=n-(i-1)%n;
			}
			break;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
} 
