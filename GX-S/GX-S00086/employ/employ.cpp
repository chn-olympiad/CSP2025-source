#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//ruguo ni chenbuchuqi nani jiuhui shibai.
int s[501];
int main()

{
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	
	int yes=0;
	int los=0;
	int dag=0;//guomian zongrenshu 
	int n,m;//定义面试人数n 录取人数m
	cin>>n>>m; //输入n和m
	
	// m=0
	if(m==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	int s1;//定义难度字符串
	cin>>s1;//输入难度字符串
	for(int i=n;i>=1;i--)
	{
		s[i]=s1%10;
		s1/=10;
	}
	//存储难度值部分
	
	//m=n
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
		if(s[i]==0) 
		{
			cout<<"0"<<endl;
			return 0;
		}
		}
		
			int a=1;
			for(int j=1;j<=n;j++) {a*=j;}
			cout<<a<<endl;
			return 0;
		
	}
	
	int c[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		//cout<<c[i]<<" ";
	}
	//存储耐心值部分
	//cout<<s[1]<<endl;
	
	//n=1
	if(n==1)
	{
		if(s[1]==1) 
		{
			cout<<"1"<<endl;
			return 0;
		}
		if(s[1]==0) 
		{
			cout<<"0"<<endl;
			return 0;
		}
	}
	
	//n=2
	if(n==2)
	{
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		
		yes=0,los=0;
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		
		cout<<dag;
	}
	
	//n=3
	if(n==3)
	{
		//123
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//132
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//213
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//231
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//312
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//321
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		cout<<dag<<endl;
	}
	
	//n=4
	if(n==4)
	{
		//1234
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(s[4]==1&&los<c[4]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//1243
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[4]) yes++;
		else los++;
		if(s[4]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//1324
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(s[4]==1&&los<c[4]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//1342
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[4]) yes++;
		else los++;
		if(s[4]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//1432
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[4]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(s[4]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//1423
		if(s[1]==1&&los<c[1]) yes++;
		else los++;
		if(s[2]==1&&los<c[4]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(s[4]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//2134
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(s[4]==1&&los<c[4]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//2143
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[4]) yes++;
		else los++;
		if(s[4]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//2314
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(s[4]==1&&los<c[4]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//2341
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[4]) yes++;
		else los++;
		if(s[4]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//2413
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[4]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(s[4]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//2431
		if(s[1]==1&&los<c[2]) yes++;
		else los++;
		if(s[2]==1&&los<c[4]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(s[4]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//3124
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(s[4]==1&&los<c[4]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//3142
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[4]) yes++;
		else los++;
		if(s[4]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//3214
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(s[4]==1&&los<c[4]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//3241
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[4]) yes++;
		else los++;
		if(s[4]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//3412
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[4]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(s[4]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//3421
		if(s[1]==1&&los<c[3]) yes++;
		else los++;
		if(s[2]==1&&los<c[4]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(s[4]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//4123
		if(s[1]==1&&los<c[4]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(s[4]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//4132
		if(s[1]==1&&los<c[4]) yes++;
		else los++;
		if(s[2]==1&&los<c[1]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(s[4]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//4213
		if(s[1]==1&&los<c[4]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(s[4]==1&&los<c[3]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//4231
		if(s[1]==1&&los<c[4]) yes++;
		else los++;
		if(s[2]==1&&los<c[2]) yes++;
		else los++;
		if(s[3]==1&&los<c[3]) yes++;
		else los++;
		if(s[4]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//4312
		if(s[1]==1&&los<c[4]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[1]) yes++;
		else los++;
		if(s[4]==1&&los<c[2]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
		//4321
		if(s[1]==1&&los<c[4]) yes++;
		else los++;
		if(s[2]==1&&los<c[3]) yes++;
		else los++;
		if(s[3]==1&&los<c[2]) yes++;
		else los++;
		if(s[4]==1&&los<c[1]) yes++;
		else los++;
		if(yes>=m) dag++;
		yes=0,los=0;
		
	}
	return 0;
}
