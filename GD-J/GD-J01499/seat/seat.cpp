#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat3.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[25];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    int rp;
    sort(a+1,a+n*m+1,cmd);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r) rp=i;
    }
    int rm,rn;
    if(rp%n==0) rm=rp/n;
    else rm=rp/n + 1;
    if(rp%n==0)
    {
    	if(rm%2!=0) rn=n;
    	else rn=1;
	}
	else
	{
		if(rm%2==0) rn=n-(rp%n)+1;
    	else rn=rp%n;
	}
    cout<<rm<<' '<<rn;
    return 0;
}

