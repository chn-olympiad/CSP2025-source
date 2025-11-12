#include<bits/stdc++.h>
using namespace std;
struct FSI{
    template<typename T>
    FSI& operator >> (T&res){
        res=0;T f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
        while(isdigit(ch)){res=(res*10)+(ch-48);ch=getchar();}
        res*=f;
        return *this;
    }
} scan;
typedef long long ll;
const int N=1e5+5;
struct node{
    int a,b,c;
} a[N];
priority_queue<int,vector<int>,greater<int> > q;
void work(){
    int n,mx;
    scan>>n;
    mx=n/2;
    for(int i=1;i<=n;i++) scan>>a[i].a>>a[i].b>>a[i].c;
    ll res=0,tmp=0;
//  can everyone gets it max?
    tmp=0;
    int lka=0,lkb=0,lkc=0,lkab=0,lkac=0,lkbc=0,lkabc=0;
    for(int i=1;i<=n;i++){
        if(a[i].a==a[i].b&&a[i].b==a[i].c) lkabc++;
        else if(a[i].a==a[i].b&&a[i].a>a[i].c) lkab++;
        else if(a[i].b==a[i].c&&a[i].b>a[i].a) lkbc++;
        else if(a[i].a==a[i].c&&a[i].a>a[i].b) lkac++;
        else if(a[i].a>max(a[i].b,a[i].c)) lka++;
        else if(a[i].b>max(a[i].a,a[i].c)) lkb++;
        else if(a[i].c>max(a[i].a,a[i].b)) lkc++;
        tmp+=max(a[i].a,max(a[i].b,a[i].c));
    }
//  lkab,lkac,lkbc,lkabc can freely go to anywhere they like.
    if(lka<=mx&&lkb<=mx&&lkc<=mx) res=max(res,tmp);
//    printf("res = %lld\n",res);
//  regard a as priority
    while(!q.empty()) q.pop();
    tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=a[i].a;
        q.emplace(a[i].a-max(a[i].b,a[i].c));
        if(q.size()>mx) tmp-=q.top(),q.pop();
    }
    res=max(res,tmp);
//   printf("res = %lld\n",res);
//  regard b as priority
    while(!q.empty()) q.pop();
    tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=a[i].b;
        q.emplace(a[i].b-max(a[i].a,a[i].c));
        if(q.size()>mx) tmp-=q.top(),q.pop();
    }
    res=max(res,tmp);
//    printf("res = %lld\n",res);
//  regard c as priority
    while(!q.empty()) q.pop();
    tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=a[i].c;
        q.emplace(a[i].c-max(a[i].a,a[i].b));
        if(q.size()>mx) tmp-=q.top(),q.pop();
    }
    res=max(res,tmp);
//    printf("res = %lld\n",res);
    printf("%lld\n",res);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scan>>T;
    while(T--) work();
    return 0;
}