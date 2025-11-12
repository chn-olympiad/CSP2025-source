#include <bits/stdc++.h>
using namespace std;
    int b[100010];
    int ans=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    int a[100010];
    int k;cin>>k;
    int a1=2,a2=1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n&&!b[i];i++)
    {
        for(int j=0;j+i<=n&&!b[j];j++)
        {
            int sum=a[j+1];
            for(int q=j+2;q<=j+i;q++)
            {
                if(b[q]==1) {sum=-1;break;}
                sum=sum^a[q];
            }
            if(sum==k)
            {
                ans++;
                for(int q=j+1;q<=j+i;q++)
                {
                    b[q]=1;
                }
                i++;j++;
            }
        }
    }
    cout<<ans;
    return 0;
}
