#include <iostream>
using namespace std;
int a[100010];
bool book[100010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,s;
    cin >> n >> s;
    int ans=0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(book[i]==1) break;
            if(book[j]==1) continue;
            if(i==j&&i==s)
            {
                ans++;
                book[i]=1;
                break;
            }
            int sum=a[i],f=0;
            for(int k=i+1;k<=j;k++)
            {
                sum^=a[k];
                if(book[k]==1)
                {
                    break;
                    f=1;
                }
            }
            if(f==1) continue;
            if(sum==s)
            {
                ans++;
                for(int k=i+1;k<j;k++) book[k]=1;
            }
        }
    }
    cout << ans;
    return 0;
}
