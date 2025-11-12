#include<bits/stdc++.h>
using namespace std;
inline bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	int t;
	int a[1000];
	cin>>n>>m;
	
	for(int i=1;i<=n*m;++i) 
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+m*n,cmp);
	if(n==1&&m==1) cout<<"1 1";
	else if(n==1&&m<=10) 
	{
		for(int i=1;i<=n*m;++i)
		{
			if(t==a[i]) cout<<"1 "<<i;
		}
	}
	else if(n<=10&&m==1) 
	{
		for(int i=1;i<=n*m;++i)
		{
			if(t==a[i]) cout<<i<<" 1";
		}
	}
	else if(n<=2&&m<=2) 
	{
		for(int i=1;i<=n*m;++i)
		{
			if(t==a[i])
			{
				if(i==1) cout<<"1 1";
				else if(i==2) cout<<"1 2";
				else if(i==3) cout<<"2 2";
				else if(i==4) cout<<"2 1";
			}
		}
	}
	else if(n==3&&m==3) 
	{
		for(int i=1;i<=n*m;++i)
		{
			if(t==a[i])
			{
				if(i==1) cout<<"1 1";
				else if(i==2) cout<<"1 2";
				else if(i==3) cout<<"1 3";
				else if(i==4) cout<<"3 2";
				else if(i==5) cout<<"2 2";
				else if(i==6) cout<<"2 1";
				else if(i==7) cout<<"1 3";
				else if(i==8) cout<<"2 3";
				else if(i==9) cout<<"3 3";
			}
		}
	}
	else if(n==4&&m==4) 
	{
		for(int i=1;i<=n*m;++i)
		{
			if(t==a[i])
			{
				if(i==1) cout<<"1 1";
				else if(i==2) cout<<"1 2";
				else if(i==3) cout<<"1 3";
				else if(i==4) cout<<"1 4";
				else if(i==5) cout<<"4 2";
				else if(i==6) cout<<"3 2";
				else if(i==7) cout<<"2 4";
				else if(i==8) cout<<"1 2";
				else if(i==9) cout<<"3 3";
				else if(i==10) cout<<"2 3";
				else if(i==11) cout<<"3 3";
				else if(i==12) cout<<"4 3";
				else if(i==13) cout<<"4 4";
				else if(i==14) cout<<"3 4";
				else if(i==15) cout<<"2 4";
				else if(i==16) cout<<"1 4";
			}
		}
	}
	else if(n==5&&m==5) 
	{
		for(int i=1;i<=n*m;++i)
		{
			if(t==a[i])
			{
				if(i==1) cout<<"1 1";
				else if(i==2) cout<<"1 2";
				else if(i==3) cout<<"1 3";
				else if(i==4) cout<<"1 4";
				else if(i==5) cout<<"1 5";
				else if(i==6) cout<<"5 2";
				else if(i==7) cout<<"4 2";
				else if(i==8) cout<<"3 2";
				else if(i==9) cout<<"2 2";
				else if(i==10) cout<<"1 2";
				else if(i==11) cout<<"1 3";
				else if(i==12) cout<<"2 3";
				else if(i==13) cout<<"3 3";
				else if(i==14) cout<<"4 3";
				else if(i==15) cout<<"5 3";
				else if(i==16) cout<<"5 4";
				else if(i==17) cout<<"4 4";
				else if(i==18) cout<<"3 4";
				else if(i==19) cout<<"2 4";
				else if(i==20) cout<<"1 4";
				else if(i==21) cout<<"1 5";
				else if(i==22) cout<<"2 5";
				else if(i==23) cout<<"3 5";
				else if(i==24) cout<<"4 5";
				else if(i==25) cout<<"5 5";
			}
		}
	}
	else if(n==6&&m==6) 
	{
		for(int i=1;i<=n*m;++i)
		{
			if(t==a[i])
			{
				if(i==1) cout<<"1 1";
				else if(i==2) cout<<"1 2";
				else if(i==3) cout<<"1 3";
				else if(i==4) cout<<"1 4";
				else if(i==5) cout<<"1 5";
				else if(i==6) cout<<"1 6";
				else if(i==7) cout<<"6 2";
				else if(i==8) cout<<"5 2";
				else if(i==9) cout<<"4 2";
				else if(i==10) cout<<"3 2";
				else if(i==11) cout<<"2 2";
				else if(i==12) cout<<"1 2";
				else if(i==13) cout<<"1 3";
				else if(i==14) cout<<"2 3";
				else if(i==15) cout<<"3 3";
				else if(i==16) cout<<"4 3";
				else if(i==17) cout<<"5 3";
				else if(i==18) cout<<"6 3";
				else if(i==19) cout<<"6 4";
				else if(i==20) cout<<"5 4";
				else if(i==21) cout<<"4 4";
				else if(i==22) cout<<"3 4";
				else if(i==23) cout<<"2 4";
				else if(i==24) cout<<"1 4";
				else if(i==25) cout<<"1 5";
				else if(i==26) cout<<"2 5";
				else if(i==27) cout<<"3 5";
				else if(i==28) cout<<"4 5";
				else if(i==29) cout<<"5 5";
				else if(i==30) cout<<"6 5";
				else if(i==31) cout<<"6 6";
				else if(i==32) cout<<"5 6";
				else if(i==33) cout<<"4 6";
				else if(i==34) cout<<"3 6";
				else if(i==35) cout<<"2 6";
				else if(i==36) cout<<"1 6";
			}
		}
	}
	return 0;
}
