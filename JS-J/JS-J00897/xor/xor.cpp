#include <iostream>

using namespace std;
int n,k;
int a[500050];
int cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int num=a[1],i=1;
    while(i<=n)
    {
        i++;
        if(num==k)
        {
            cnt++;
            num=a[i];
        }
        else
        {
            num^=a[i];
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
