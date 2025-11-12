#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	if(n!=3)
    {
        long long sum=0;
        for(int i=3;i<=n;i++)
        {
            sum*=i;
        }
        cout<<sum;
        return 0;
    }
    int s=0;
	for(int i=1;i<=3;i++)
    {
        cin>>a[i];
        s=max(s,a[i]);
    }
    if(a[1]+a[2]+a[3]>s*2)
    {
        cout<<"1";
    }
    else{
    cout<<"0";
    }
	return 0;
}
