/*
1.for循环是否写对
2.是否把==写成=
3.倒序遍历是否i--
4.是否溢出，是否开long long
5.数组是否越界，特别注意a[i-k]
6.是否freopen写对
7.n*m是否<=m
8.是否包含：left,right,next,prev,y0,yn,j0,j1,jn等变量名
9.是否删debug语句
//*/
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]^=a[i-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)if((a[i]^a[j])==k)
		{
			f[i]=f[j]+1;break;
		}
		f[i]=max(f[i],f[i-1]);
	}
	/*
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<f[i]<<" ";
	/*/
	cout<<f[n];
	//*/
	return 0;
}

