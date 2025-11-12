 #include <bits/stdc++.h> 
 using namespace std;
 
 bool cmp(int a,int b)
 {
 	return a>b;
 }
 int main()
 {
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,xiao_R,www; 
	cin>>n>>m;
	int x[n*m]={0};
	for(int i=0;i<n*m;i++)
		cin>>x[i];
	xiao_R=x[0];
	sort(x,x+m*n,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(x[i]==xiao_R)www=i+1;
	}
	bool fff=www%n;
	if((www/n+fff-1)%2==0)
	{

		cout<<www/n+fff<<' ';
		if(fff)
		cout<<www%n;
		else 
		cout<<n;
	}
	else
	{
		cout<<www/n+1<<' ';
		cout<<n-www%n+1;
	}
 	return 0;
 }
