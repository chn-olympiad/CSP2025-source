#include<bits/stdc++.h>
using namespace std;
int n,q,w=0;
string s;
string d;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",s);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",d);
    }
    for(int i=q;i<=n;i++)
    {
         if(s==d)
        {
            w++;
        }
    }
    q=1;
   for(int i=1;i<=q;q++)
   {
       cout<<w;
   }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
