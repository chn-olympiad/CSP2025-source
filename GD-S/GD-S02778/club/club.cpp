#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n;
struct ok{
    int a,b,c,i;
}a[100005],b[100005],c[100005];

bool cmp1(ok a,ok b){
    return a.a-a.b-a.c>b.a-b.b-b.c;
}
bool cmp2(ok a,ok b){
    return a.b-a.a-a.c>b.b-b.a-b.c;
}
bool cmp3(ok a,ok b){
    return a.c-a.a-a.b>b.c-b.a-b.b;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].i=i;
        }
        memcpy(b,a,sizeof a);
        memcpy(c,b,sizeof b);
        sort(a+1,a+n+1,cmp1);
        sort(b+1,b+n+1,cmp2);
        sort(c+1,c+n+1,cmp3);

        int _a=0,_b=0,_c=0,ans=0,z=0,ca,cb,cc;
        for(int i=1;i<=n;i++){
            ca=(_a<(n>>1)?a[i].a:INT_MIN);
            cb=(_b<(n>>1)?a[i].b:INT_MIN);
            cc=(_c<(n>>1)?a[i].c:INT_MIN);
            if(ca-cb-cc>cb-ca-cc&&ca-cb-cc>cc-ca-cb){
                _a++;
                z+=a[i].a;
            }
            else if(cb-ca-cc>ca-cb-cc&&cb-ca-cc>cc-ca-cb){
                _b++;
                z+=a[i].b;
            }
            else if(cc-ca-cb>ca-cb-cc&&cc-ca-cb>cb-ca-cc){
                _c++;
                z+=a[i].c;
            }
        }
        ans=z;

        _a=_b=_c=z=0;
        for(int i=1;i<=n;i++){
            ca=(_a<(n>>1)?b[i].a:INT_MIN);
            cb=(_b<(n>>1)?b[i].b:INT_MIN);
            cc=(_c<(n>>1)?b[i].c:INT_MIN);
            if(ca-cb-cc>cb-ca-cc&&ca-cb-cc>cc-ca-cb){
                _a++;
                z+=b[i].a;
            }
            else if(cb-ca-cc>ca-cb-cc&&cb-ca-cc>cc-ca-cb){
                _b++;
                z+=b[i].b;
            }
            else if(cc-ca-cb>ca-cb-cc&&cc-ca-cb>cb-ca-cc){
                _c++;
                z+=b[i].c;
            }
        }
        ans=max(ans,z);

        _a=_b=_c=z=0;
        for(int i=1;i<=n;i++){
            ca=(_a<(n>>1)?c[i].a:INT_MIN);
            cb=(_b<(n>>1)?c[i].b:INT_MIN);
            cc=(_c<(n>>1)?c[i].c:INT_MIN);
            if(ca-cb-cc>cb-ca-cc&&ca-cb-cc>cc-ca-cb){
                _a++;
                z+=c[i].a;
            }
            else if(cb-ca-cc>ca-cb-cc&&cb-ca-cc>cc-ca-cb){
                _b++;
                z+=c[i].b;
            }
            else if(cc-ca-cb>ca-cb-cc&&cc-ca-cb>cb-ca-cc){
                _c++;
                z+=c[i].c;
            }
        }
        ans=max(ans,z);
        cout<<ans<<endl;
    }
}

