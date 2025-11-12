#include<bits/stdc++.h>
#define int long long
using namespace std;
const int D=5e5+5;
struct node {
    int bi,ei;
};node b[D];
int a[D];
int q;
bool cmp(node u,node v)
{
    return u.ei<v.ei;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=i;j<=n;j++){
            ans^=a[j];
            if(ans==k) b[++q].bi=i,b[q].ei=j;
        }
    }
    sort(b+1,b+1+q,cmp);
    int cnt=1;
    int temp=b[1].ei;
    for(int i=2;i<=q;i++){
        if(b[i].bi>temp){
            cnt++;
            temp=b[i].ei;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
