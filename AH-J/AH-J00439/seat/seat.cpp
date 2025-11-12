#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b=n*m;
    int ans;
    for(int i=1;i<=b;i++) cin>>a[i],ans=a[1];
    sort(a+1,a+1+b,cmp);
    for(int i=1;i<=b;i++)
    if(a[i]==ans)
    {
		int JJ=i/n;
		if(i%n!=0) JJ++;
		cout<<JJ;
		cout<<' ';
		if(JJ%2==1) 
		{
			if(i%n==0) cout<<n;
			else cout<<i%n;
		}
		else
		{
			if(i%n==0) cout<<1;
			else cout<<(JJ-1)*n+i%n-1;
		}
		return 0;
	}
    return 0;
}
