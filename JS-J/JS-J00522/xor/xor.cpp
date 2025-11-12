#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=0,k,a[N];
struct node{
    int l,r;
};
vector<node> b;
bool cmp(node x,node y)
{
    return x.r<y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int j=i,num=a[i];
        while(num!=k && j<=n)
        {
            j++;
            num^=a[j];
        }
        if(num==k){
            b.push_back({i,j});
        }
    }
    sort(b.begin(),b.end(),cmp);
    int lt=0;
    for(int i=0;i<b.size();i++)
    {
        if(b[i].l>lt){
            ans++;
            lt=b[i].r;
        }
    }
    cout<<ans<<endl;
    return 0;
}
