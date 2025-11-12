#include<bits/stdc++.h>
using namespace std;
const int N=505;
int m,n,a[N];
int place=1;//小R的名次 
int row,col,lft;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++)scanf("%d",&a[i]);
	
	
	for(int i=2;i<=(n*m);i++)//1.算出place 
	{
		if(a[i]>a[1])place++;
	}
	
	
	//2.算出行列
	col = (place+n-1)/n;
	lft = place-(col-1)*n;
	if(lft==0) lft=n;//lft=1,2,3,....n 
//	cout<<lft<<" ";
	if(col%2 == 1)
	{
		row=lft;
	} 
	else 
	{
		row=n-lft+1;
	}
	printf("%d %d",col,row);
	return 0;
}

