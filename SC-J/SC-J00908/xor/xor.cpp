#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    vector<int>A(n);
    vector<bool>visited(n,false);
    int num=0,h=n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(A[i]==k)
        {
            visited[i]=true;
            num++;
            h--;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int q=0;
            for(int x=0;x<i;x++)
            {
                if(visited[j+x]==false)
                {
                    q^=A[j+x];
                }
                else q=0;
            }
            if(q==k)
            {
                for(int x=0;x<i;x++)
                {
                    visited[j+x]=false;
                }
                num++;
            }
            j+=i;
            h-=i;
        }
        if(h<i) break;
    }
    cout<<num;
    return 0;
}
