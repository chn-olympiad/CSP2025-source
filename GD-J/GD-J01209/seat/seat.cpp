#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a[1000001],index;
    cin>>n>>m;
    int len;
    len=n*m;
    int u;
    cin>>u;
    a[0]=u;
    for(int i=1;i<len;i++)
    {
        cin>>a[i];
    }
    sort(a,a+len,greater<int>());
    for(int j=0;j<len;j++)
    {
        if(a[j]==u)
        {
            index=j+1;
        }
    }
    if(index<=n) cout<<'1'<<' '<<index;
    else{
        int k,p;
        k=index/n;
        p=index%n;
        if(p==0)
        {
        	if(k%2==0)
        	{
        		cout<<k<<' '<<1;
			}
			else
			{
				cout<<k<<' '<<n;
			}
		}
		else
		{
			if((k+1)%2==0)
			{
				cout<<k+1<<' '<<n-p+1;
			}
			else
			{
				cout<<k+1<<' '<<p;
			}
		}
    }
    return 0;
}
