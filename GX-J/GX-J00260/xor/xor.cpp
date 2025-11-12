#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500050];
int b[20005][20005];
struct qujian
{
    int l,r;
    qujian(int _l,int _r){
        l=_l,r=_r;
    }
};

vector<qujian> q;
bool cmp(const qujian &a,const qujian &b)
{
    if(a.r<b.r) return 1;
    return 0;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i][i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            b[i][j]=b[j][j]^b[i][j+1];
            if(b[i][j]==k){
                q.push_back(qujian(j,i));
            }
        }
    }
    int num=q.size();
    ans=num;
    int maxnr=q[0].r;
    sort(q.begin(),q.end(),cmp);
    for(int i=1;i<num;i++){
        if(q[i].l>maxnr){
            maxnr=q[i].r;
        }
        else ans--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
