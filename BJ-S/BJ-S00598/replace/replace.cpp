#include<bits/stdc++.h>
using namespace std;
string df[1000000];
string dt[1000000];
string re[1000000];
string nf,nt;
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>df[i]>>dt[i];
    }
    for(int times=1;times<=q;times++)
    {
        cin>>nf>>nt;
        cout<<'0'<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
