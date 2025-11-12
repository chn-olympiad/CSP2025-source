#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1001],c=1,r=1,b,ji;
    cin>>n>>m;
    for(int i=1; i<=n*m; i++)
    {
        cin>>a[i];
    }
    b=a[1];
    for(int i=1; i<n*m; i++)
    {
        for(int j=1; j<n*m; j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1; i<=n*m; i++)
    {
        if(a[i]==b)
        {
            ji=i;
        }
    }
    c+=ji/(2*n);
    if(ji%(2*n)>n || ji/(2*n)>=1 && ji%(2*n)!=0)
    {
        c++;
    }
    if(c%2==1)
    {
        if(ji%n==0){
        	r=n;
		}
		else{
			r=ji%n;
		}
    }
    else
    {
        r+=n-ji%n+1;
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
