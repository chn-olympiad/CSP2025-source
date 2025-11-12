#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k;
int bl()
{
	int ansmax=0,p=1,w=0,s=0;//p 为这一区间开始元素 
	for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				s++;
			//	cout<<i<<endl;
				p=i+1,w=a[p];
				continue;
			}
			if(i==p&&w==a[p])
				continue;
			w^=a[i];
			if(w==k)
			{
				s++;
			//	cout<<p<<" "<<i<<endl;
				p=i+1,w=a[p];
				continue;
			}
		}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<bl();
	return 0;
}
