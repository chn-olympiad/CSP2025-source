#include<bits/stdc++.h>
using namespace std;
int c[505];
int a[505];
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
   int n,m,tot=0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        a[i]=i;
    }

    do
    {   int pass=0;
        for(int i=1;i<=n;i++)
        {
            if(!(s[i-1]-'0')||pass>=c[a[i]])
            {
                pass++;

            }
            }
            if(n-pass>=m)tot++;

            }while(next_permutation(a+1,a+n+1));
            cout<<tot;

}
