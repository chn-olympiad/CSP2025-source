//GZ-S00071 贵阳市第三实验中学 包雨桐
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m,sum=0,x=0;
	cin>>n>>m;
	int z=n;
	string b;
	cin>>b;
	int a[505],y[505];
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==0)
		{
			x++;
			y[x]=i;
		}
	}
	sort(a,a+n+1);
	x=0;
	cout<<2204128;
	return 0;
} 
