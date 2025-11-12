#include<bits/stdc++.h>
using namespace std;
int a[10010];
int dn,yzz,xyy;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t,n;
	int a,b,c;
	int res=0;
	cin>>t>>n;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=4;j++)
		{
			scanf("%d%d%d",&a,&b,&c);
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(a>b>c||a>c>b)
		{
			res+=a;
		}
		else if(b>a>c||b>c>a)
		{
			res+=b;
		}
		else if(c>a>b||c>b>a)
		{
			res+=c;
		}
		cout<<res;
	}
		return 0;
} 
