#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
    int a1,a2,cha,maxid;
}a[N];
int n,T,x,y,z,maxn,minn,cnt[5];
long long sum;
bool cmp(node p,node q){
    return p.cha>q.cha;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
    cin>>n;
    sum=0;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        maxn=max(max(x,y),z);
        minn=min(min(x,y),z);
        a[i].a1=maxn;
        if(maxn==x&&minn==y) a[i].a2=z,a[i].maxid=1;
        else if(maxn==x&&minn==z) a[i].a2=y,a[i].maxid=1;
        else if(maxn==z&&minn==y) a[i].a2=x,a[i].maxid=3;
        else if(maxn==z&&minn==x) a[i].a2=y,a[i].maxid=3;
        else if(maxn==y&&minn==x) a[i].a2=z,a[i].maxid=2;
        else if(maxn==y&&minn==z) a[i].a2=x,a[i].maxid=2;
        a[i].cha=a[i].a1-a[i].a2;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=3;i++) cnt[i]=0;
    for(int i=1;i<=n;i++){
        if(cnt[a[i].maxid]<n/2){
            sum+=a[i].a1;
            cnt[a[i].maxid]++;
        }
        else sum+=a[i].a2;
    }
    cout<<sum<<endl;
    }
    return 0;
}