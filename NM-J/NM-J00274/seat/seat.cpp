#include<bits/stdc++.h>
using namespace std;
int a[1000006],qwe,n,m;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	qwe=a[1];
	for(int i=1;i<=n*m;i++) 
		for(int j=i+1;j<=n*m;j++) 
			if(a[i]<=a[j]) swap(a[i],a[j]);
	for(int i=1;i<=n*m;i++) 
		{
			if(a[i]==qwe) 
				{
					if(i%n==0) cout<<i/n<<" ";
						else cout<<i/n+1<<" ";
					if((i/n+1)%2==1&&i%n!=0) cout<<i%n;
					if((i/n+1)%2==0&&i%n!=0) cout<<n-(i%n)+1;
					if((i/n+1)%2==1&&i%n==0) cout<<1;
					if((i/n+1)%2==0&&i%n==0) cout<<n;
					break;
				}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
