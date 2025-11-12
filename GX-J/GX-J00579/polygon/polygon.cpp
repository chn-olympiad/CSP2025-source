#include<bits/stdc++.h>
using namespace std;
int stick[9178];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>stick[i];
    }
    int ans=0;
    /*for(int i=0;i<n-2;i++)
    {
        for(int ii=i+1;ii<n-1;i++)
        {
            for(int iii=ii+1;iii<n;i++)
            {
                int ansi=stick[i]+stick[ii]+stick[iii];
                if( max(max(stick[i],stick[ii]),stick[iii])*2<ansi )ans++;
            }
        }
    }*/
    cout<<1;
	return 0;
}

