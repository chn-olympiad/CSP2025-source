#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int nowl[1000005],nowr[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			//cout<<"l="<<l<<" r="<<r<<endl;
			int x=a[l];
			for(int i=l+1;i<=r;i++)
			{
				if(a[i]==0&&x!=0)
				{
					if(x%2!=0)x=x-1;
				}
				else if(a[i]!=0&&x==0)
				{
					if(a[i]%2==0)x=a[i];
					else x=a[i]-1;
				}
				else if(a[i]!=0&&x!=0)
				{
					x=a[i]+x;
				}
				else if(a[i]==0&&x==0)
				{
					x=0;
				}
			}
			//cout<<"l="<<l<<" r="<<r<<" x="<<x;
			if(x==k)
			{
				cnt++;
				nowl[cnt]=l;
				nowr[cnt]=r;
				//cout<<"   "<<55555; 
			}
			//cout<<endl;
			if(x>k)break;
		}
	}
	int cntn=0,now=0;
	for(int i=1;i<=cnt;i++)
	{
		//cout<<"nowl["<<i<<"]="<<nowl[i]<<" nowr["<<i<<"]="<<nowr[i]<<endl;
		if(nowl[i]>now)
		{
			cntn++;
			now=nowr[i];
		}
	}
	cout<<cntn;
	return 0;
}