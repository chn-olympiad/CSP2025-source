#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
long long a1[maxn],a2[maxn],a3[maxn];
long long w[maxn],ffind[maxn];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
        	cin>>a1[i]>>a2[i]>>a3[i];
        	ffind[i]=a1[i]-a2[i];
		}
		if(n==2)
        {

        a1[2]+=max(a2[1],a3[1]);
		a2[2]+=max(a1[1],a3[1]);
		a3[2]+=max(a1[1],a3[1]);
		ans=max(a1[2],max(a2[2],a3[2]));
		cout<<ans;
        }
        else
        {
            for(int i=1;i<=n-1;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				if(ffind[j]>ffind[j+1])
				{
					swap(ffind[j],ffind[j+1]);
					swap(a1[j],a1[j+1]);
					swap(a2[j],a2[j+1]);
					swap(a3[j],a3[j+1]);
				}
		 }

		}

        for(int i=1;i<=n/2;i++)
        {
        	w[i]=a3[i]-a2[i];
        	ans+=a2[i];
		}
        for(int i=n;i>n/2;i--)
        {
        	w[i]=a3[i]-a1[i];
        	ans+=a1[i];
		}
		sort(w+1,w+n+1);
		for(int j=n;j>n/2;j--)
		{
			if(w[j]>=0)
			{
				ans+=w[j];
			}
		}
		cout<<ans<<endl;
    }

        }

    return 0;
}
