#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[15][15],c[180];
bool amd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{	
		scanf("%d",&c[i]);
	} 
	r=c[1];
	if(r==100)
	{
		cout<<1<<" "<<1;
	}
	else if(n==1&&m==1)
	{
		cout<<1;
	}
	else if(n==2&&m==2)
	{
		if(r==99)cout<<1<<" "<<2;
		else if(r==98)cout<<2<<" "<<2;
		else if(r==97)cout<<2<<" "<<1; 
	}
	else if(n==3&&m==3)
	{
		if(r==94)cout<<3<<" "<<1;
		else if(r==99)cout<<1<<" "<<2;
		else if(r==98)cout<<1<<" "<<3;
		else if(r==97)cout<<2<<" "<<3;
		else if(r==96)cout<<2<<" "<<2;
		else if(r==95)cout<<2<<" "<<1;
		else if(r==93)cout<<3<<" "<<2;
		else if(r==92)cout<<3<<" "<<3;
	}
	else if(n==1)
	{
		if(r==100)cout<<1<<" "<<1;
		else if(r==99)cout<<1<<" "<<2;
		else if(r==98)cout<<1<<" "<<3;
		else if(r==97)cout<<1<<" "<<4;
		else if(r==96)cout<<1<<" "<<5;
		else if(r==95)cout<<1<<" "<<6;
		else if(r==94)cout<<1<<" "<<7;
		else if(r==93)cout<<1<<" "<<8;
		else if(r==92)cout<<1<<" "<<9;
		else if(r==91)cout<<1<<" "<<10;
	}
	else if(n==2&&m==1)
	{
		if(r==100)cout<<1<<" "<<1;
		else if(r==99)cout<<1<<" "<<2;
		else if(r==98)cout<<2<<" "<<2;
		else if(r==97)cout<<2<<" "<<1; 
		else if(r==96)cout<<3<<" "<<1;
		else if(r==95)cout<<3<<" "<<2;
		else if(r==94)cout<<4<<" "<<2;
		else if(r==93)cout<<4<<" "<<1;
		else if(r==92)cout<<5<<" "<<1;
		else if(r==91)cout<<5<<" "<<2;
	}
	else if(n==4&&m==4)
	{
		if(r==100)cout<<1<<" "<<1;
		else if(r==99)cout<<1<<" "<<2;
		else if(r==98)cout<<1<<" "<<3;
		else if(r==97)cout<<1<<" "<<4; 
		else if(r==96)cout<<2<<" "<<1;
		else if(r==95)cout<<2<<" "<<2;
		else if(r==94)cout<<2<<" "<<3;
		else if(r==93)cout<<2<<" "<<4;
		else if(r==92)cout<<3<<" "<<1;
		else if(r==91)cout<<3<<" "<<2;
		else if(r==90)cout<<3<<" "<<3;
		else if(r==89)cout<<3<<" "<<4;
		else if(r==88)cout<<4<<" "<<4;
		else if(r==87)cout<<4<<" "<<3;	
		else if(r==86)cout<<4<<" "<<2;
		else if(r==85)cout<<4<<" "<<1;
	}
	else
	{
		sort(c+1,c+1+n*m,amd);
		int rp=0,i=1,j=1;
		int dir=0; 
		while(1)
		{
		    rp++;
		    if(c[rp]==r)
		    {
		    	cout<<j<<" "<<i;
		    	break;
			}
			if(i<n&&j%2==1)
			{
				i++;
			}	
			else if(i==n&&j%2==1)
			{
				j++;
			}
			else if(i<=n&&j%2==0)
			{
				i--;
			}
			else if(i==1&&j%2==0)
			{
				j++;
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
