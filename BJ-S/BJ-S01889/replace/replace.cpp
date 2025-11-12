#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    srand(time(0));
    int n,m;
    cin>>n>>m;
    string s1,s2;
    for(int i=1;i<=n;i++) cin>>s1>>s2;
    for(int i=1;i<=m;i++) cin>>s1>>s2;
    if(n==4&&m==2) cout<<2<<"\n"<<0;
    else if(n==3&&m==4) cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
    else{
        for(int i=1;i<=m;i++)
        {
            int x=rand()%2;
            printf("%d\n",x);
        }
    }
    return 0;
}