#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    int num = 0,maxn = 0,cnt = 0;
    for(int i = 3;i<=n;i++)
    {
        num = max(a[i],num);
        maxn = max(a[i],maxn);
        num+=num;
        for(int i = 3;i<=n;i++)
        {
            if(num>=2*maxn)
            {
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
