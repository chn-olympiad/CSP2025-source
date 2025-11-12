#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool sp(int x,int y)
{
	return x>y;
};
int b[10][10];
int a[100];
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	
	int num=m*n;
	int op=0;
	
	int q=0;//lie
	int p=0;//hang
	int k=0;//zhuang tai
	
	for(int i=0;i<num;i++)
	{
		cin>>a[i];
	}
	int me=a[0];
	sort(a,a+num+1,sp);
	//for(int i=0;i<num;i++)
	//{
	///	cout<<a[i]<<" ";
	//}
	
for(int j=0;j<num;j++)//j = pai xv hou de lie biao 
	{
		b[p][q]=a[j];
		if(q==n-1 && p%2==0)
		{
			p+=1;
			k=1;	
			op=1;
		}
		if(q==0 && p%2==1)
		{
			p+=1;
			k=0;
			op=1;
		}		
		if(k==0 && op==0) 
		{
			q++;
			
		}
		if(k==1 && op==0)
		{
			q--;
			
		}
		op=0;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[i][j]==me)
			{
				cout<<i+1<<" "<<j+1;
			}
		}
	}
	

	
	return 0;
}