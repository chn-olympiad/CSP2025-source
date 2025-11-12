#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> sco(n*m);
    for(int i=0;i<n*m;i++) cin>>sco[i];
    int rSco=sco[0];
    sort(sco.begin(),sco.end(),cmp);
    int p;
    for(int i=0;i<n*m;i++)
    {
        if(sco[i]==rSco)
        {
            p=i+1;
            break;
        }
    }
    vector<int> ar;
    ar.emplace_back(1);
    for(int i=1;i<=n;i++) ar.emplace_back(i);
    for(int i=n;i>=2;i--) ar.emplace_back(i);
    int tmp=p%(2*n);
    int r=ar[tmp];
    double tp=p;
    int c=ceil(tp/n);
    cout<<c<<' '<<r;
    return 0;
}
