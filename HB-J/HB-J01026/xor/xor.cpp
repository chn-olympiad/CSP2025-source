#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=998244353;
int n,k,A[N],sum[N];
struct Node{int l,r;};
vector<Node> B;
int query(int l,int r)
{
    return sum[r]^sum[l-1];
}
bool cmp(Node a,Node b)
{
    if(a.l!=b.l) return a.l<b.l;
    else return a.r<b.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^A[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int qry=query(i,j);
            if(qry==k) B.push_back({i,j});
        }
    }
    stable_sort(B.begin(),B.end(),cmp);
    int last=B[0].r,cnt=1;
    for(int i=1;i<(int)B.size();i++)
        if(last<B[i].l)
            last=B[i].r,cnt++;
    cout<<cnt<<endl;
    return 0;
}
