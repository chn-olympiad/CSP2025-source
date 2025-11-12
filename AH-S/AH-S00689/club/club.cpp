#include<bits/stdc++.h>
#define int long long
using namespace std;
struct club{
    int a,b,c;
}x[100005];
int T,n;
int cnt[10];
int check(int a,int b,int c){
    if(cnt[a]<n/2){
        cnt[a]++;
        return a;
    }
    if(cnt[b]<n/2){
        cnt[b]++;
        return b;
    }
    if(cnt[c]<n/2){
        cnt[c]++;
        return c;
    }
}
bool cmp(club a,club b){
    int ma=max({a.a,a.b,a.c});
    int m2a=a.a+a.b+a.c-ma-min({a.a,a.b,a.c});
    int m3a=min({a.a,a.b,a.c});
    int mb=max({b.a,b.b,b.c});
    int m2b=b.a+b.b+b.c-mb-min({b.a,b.b,b.c});
    int m3b=min({b.a,b.b,b.c});
    if(ma-m2a==mb-m2b)
        return m2a-m3a>m2b-m3b;
    return ma-m2a>mb-m2b;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++)
            cin>>x[i].a>>x[i].b>>x[i].c;
        sort(x+1,x+n+1,cmp);
        for(int i=1;i<=n;i++){
            int k=0;
            if(x[i].a>=x[i].b&&x[i].b>=x[i].c) k=check(1,2,3);
            else if(x[i].a>=x[i].c&&x[i].c>=x[i].b) k=check(1,3,2);
            else if(x[i].b>=x[i].a&&x[i].a>=x[i].c) k=check(2,1,3);
            else if(x[i].b>=x[i].c&&x[i].c>=x[i].a) k=check(2,3,1);
            else if(x[i].c>=x[i].a&&x[i].a>=x[i].b) k=check(3,1,2);
            else if(x[i].c>=x[i].b&&x[i].b>=x[i].a) k=check(3,2,1);
            if(k==1) sum+=x[i].a;
            if(k==2) sum+=x[i].b;
            if(k==3) sum+=x[i].c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
