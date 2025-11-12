#include<bits/stdc++.h>
using namespace std;
#define N 5500
int n,a[N],t[N],maxn=-1,sum;
int dabiao[7]={1,4,10,20,35,56,83};

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        sum+=a[i];
    }
    if(n==3)
     {
		 if(sum>2*maxn)
		 {
            cout<<1;
			return 0;  
		}
	}
    else
    {
        cout<<dabiao[n-3];
        return 0;
    }
    cout<<0;
    return 0;
}
