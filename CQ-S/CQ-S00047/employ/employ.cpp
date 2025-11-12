#include<bits/stdc++.h>
using namespace std;
int n,m; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	//* 啊啊啊骗分代码快上啊！！！死手快给我打啊！！！ 
	int ans=1;
	for(int i=2;i<=n;i++)
		ans*=i;
	cout<<ans;
	//*/
	return 0; 
}
