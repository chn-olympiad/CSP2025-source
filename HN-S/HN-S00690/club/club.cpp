#include<bits/stdc++.h>
using namespace std;
int t,n,a[50005],b[50005],c[50005],a1=0,b1=0,c1=0,x=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
	    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	   	for(int i=1;i<=n;i++)
	    {
	    	int maxn=0;
	        if(a1<n/2&&a[i]>b[i]&&a[i]>c[i]) a1++,maxn=a[i];
	        if(b1<n/2&&b[i]>maxn&&b[i]>c[i]) b1++,maxn=b[i];
	        if(c1<n/2&&c[i]>maxn) c1++,maxn=c[i];
	        x+=maxn;
        }
        cout<<x<<endl;
        x=0;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
