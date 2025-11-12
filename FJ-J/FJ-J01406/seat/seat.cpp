#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int r;
bool bo=0;
int nowh=0,nowl=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	/*
	for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}
	*/
	nowh=0;
	nowl=1;
	for(int i=1;i<=n*m;i++)
	{
		if(nowl%2==1)
		{
			nowh++;
		}
		if(nowl%2==0){
			nowh--;
		}
		if(nowh==n+1)
		{
			nowl++;
			nowh=n;
		}
		if(nowh==0)
		{
			nowl++;
			nowh=1;
		}
		//cout<<a[i]<<" "<<nowl<<" "<<nowh<<endl;//
		if(a[i]==r)
		{
			cout<<nowl<<" "<<nowh;
			//return 0;
		}
	}
	return 0;
}
