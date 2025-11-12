#include<bits/stdc++.h>
using namespace std;
int ans,cnt,zzc;
int n,m,k;
int a[50010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(m==0)
	{
		if(n<=2)
		{
			if(n==2)
				cout<<1;
			else
				cout<<0;
		}
		else
		{
			if(n==1)
				cout<<0;
			else cout<<n/2;
		}
	}
	else 
	{
		ans=n;
		cnt=n;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				cnt--;
			}
		}
		int x=a[n];
		int t=rand()%x;
		cout<<t;
	}
	return 0;
}
//16:00~20:00 4h
//20t->5/t
//1~12->60
