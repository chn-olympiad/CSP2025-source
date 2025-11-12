#include <bits/stdc++.h>
using namespace std;
int m,n,a[200],i=1,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int t=a[1];
    for(int i=1;i<=m*n;i++)
        for(int j=i+1;j<=m*n;j++)
            if(a[i]<a[j])
            {
				x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
    for(int i=1;i<=m*n;i++)
    if(a[i]==t) {t=i; break;}
    for(i=1;i<=m;i++)
    {
	    if(n*i>=t)
		{
			if(i%2==0)
		    cout<<i<<" "<<i*n-t+1<<endl;
		    else 
		    cout<<i<<" "<<n-(i*n-t)<<endl;
			break;
		}
	}
    return 0;
}
