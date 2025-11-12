#include<bits/stdc++.h>
using namespace std;
int a[210];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int tmp=a[1],pos;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(tmp==a[i])
		{
			pos=i;
			break;
		}
	}
//	cout<<pos;
	int lie=ceil(pos*1.0/n),hang;
	if(lie%2)
		hang=m-(lie*n-pos);
	else
		hang=lie*n-pos+1;
	cout<<lie<<" "<<hang;
    return 0;
}

