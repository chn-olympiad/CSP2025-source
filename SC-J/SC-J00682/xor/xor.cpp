#include<bits/stdc++.h>
using namespace std;
int a[514114],b[524288];//我的房子还蛮大的 
int fl[567890];
int n,k,ans=0;
int f(int x,int y)
{
	if(x==y)return a[x];
	if(x==1)return b[y];
	return b[y]^b[x-1];
}
int fi()
{
	for(int i=1;i<=n;i++)if(fl[i]!=1)return i;
	return n+1;
}
bool ff(int&l,int &r)//稍微加点速 
{
	int x;
	for(int i=1;i<l;i++)x+=fl[i];
	for(int i=l;i<=r;i++){
		x+=fl[i];
		if(x>=1)return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	scanf("%d",&a[1]);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]^b[i-1];//xorxorxor 我是超级异或入 
	}
	//用个贪心 
	for(int o=0;o<n;o++){
		for(int i=fi();i<=n;i++){
			int j=i+o;
			if(!ff(i,j))continue;
			if(f(i,j)==k){
				ans++;
				fl[i]=1;fl[j+1]=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
	是pre我们没救了 
	 
 
*/
