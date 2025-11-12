#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	
	int a=0,b=0;//a为列b为行
	cin>>b>>a; 
	int s=0,xr=0;//xr为小R成绩 
	int number[1001]={0};
	int sort_number[1001]={0};
	for(int i=0;i<(a*b);i++) 
	{
		cin>>s;
		number[i]=s;
		sort_number[i]=s;
	}
	xr=number[0];
	sort(sort_number,sort_number + (a*b));
	int weishu=0;
	for(int i=0;i<(a*b);i++)
	{
		if(sort_number[i]==xr)
		{
			weishu=i+1;
			break;
		}
	}
	weishu=(a*b)-weishu+1;
	
	int xr_a=0,xr_b=0;//a为列b为行
	if(weishu % b != 0)//不能整除 
	{
		xr_a=(weishu/b)+1;
		if(xr_a %2==0)//列为偶数从下数 
		{
			xr_b=b-(weishu%b)+1;
		}
		else{
			xr_b=weishu%b;
		}
	}
	else
	{
		xr_a=weishu/b;
		if(xr_a %2 ==0)
		{
			xr_b=1;
		}
		else{
			xr_b=b;
		}
	}
	cout<<xr_a<<" "<<xr_b;
	freopen("seat.out","w",stdout);
	return 0;
}
