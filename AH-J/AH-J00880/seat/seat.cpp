#include<bits/stdc++.h>
using namespace std;
int n,m,a1,nm,i1=1;
int a[114];//,b[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
//ha ji mi bao you wo na shen er
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    a[1]=a1;
    nm=n*m;
    for(int i=2;i<=nm;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+1+nm,cmp);
	int x=1;
	while(x<=m)
	{
		if(x%2==1)
		{
		for(int y=1;y<=n;y++)
			{
				//cout<<x<<" "<<y<<" "<<a[i1]<<endl;
				if(a[i1++]==a1)
				{
				cout<<x<<" "<<y;
				return 0;
				}
			}	
		}
		else
		{
			for(int y=n;y>=1;y--)
			{//cout<<x<<" "<<y<<" "<<a[i1]<<endl;
				if(a[i1++]==a1)
				{
				cout<<x<<" "<<y;
				return 0;
				}
			}	
		}
		x++;
	}
    return 0;
    }
