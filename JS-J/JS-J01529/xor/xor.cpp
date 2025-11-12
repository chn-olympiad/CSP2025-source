#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0,cnt=0;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        sum=0;
        for(int j=i;j<=n;j++)
        {
            sum=sum^a[j];
            if(sum==k)
            {
                cnt++;
                i=j;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
