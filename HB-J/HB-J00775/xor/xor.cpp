#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int _longsize;
int book[500005];
int yu(int x,int y){
	int xsize=0,ysize=0;
	int xx=0,xxx=1,yy=0,yyy=1,zz=0;
	while(x!=0){
		xx=xx+x%2*xxx;
		xxx*=10;
		x/=2;
		xsize++;
	}
	while(y!=0){
		yy=yy+y%2*yyy;
		y/=2;
		yyy*=10;
		ysize++;
	}
	if(xsize>ysize){
		_longsize=xsize;
	}
	else{
		_longsize=ysize;
	}
	int jj=1;
	for(int i=0;i<_longsize;i++)
	{
		if(xx%10!=yy%10){
			zz=zz+jj;
		}
		jj*=10;
		xx/=10;
		yy/=10;
	}
	int f=1,q=0;
	for(int i=0;i<_longsize;i++)
	{
		q+=zz%10*f;
		zz/=10;
		f*=2;
	}
	_longsize=0;
	return q;
}
int main()
{
	int sum=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			sum++;
		}
		book[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		int num=a[i];
		for(int j=i;j<n;j++){
			if(book[j]==1)
			{
				break;
			}
			else{
				num=yu(num,a[j]);
				if(num==k){
					sum++;
					for(int k=i;k<=j;k++)
					{
						book[k]=1;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
