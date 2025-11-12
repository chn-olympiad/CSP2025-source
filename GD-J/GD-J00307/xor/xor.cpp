#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
 int n,k,a[N],ans;
 struct jgt
 {
 	int l;
	int r;
 }b[N];
 int abc(int l,int r)
 {
 	int num=0;
 	for(int i=l;i<=r;i++)num=num^a[i];
 	return num;
 }
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n;j++)
    	{
    		if(abc(i,j)==k)
			{
			b[++ans].l=i;
			b[ans].r=j;	
			}
			else if(i==j&&a[i]==k)
			{
				b[++ans].l=i;
				b[ans].r=j;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=ans;i++)
	{
	if(b[i].l>b[i-1].r)sum++;	
	}
	cout<<sum;
	return 0;
}
