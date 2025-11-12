#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct pt{
    int val,id;
};

struct node{
    pt a[5];
};
node x[100005];

bool cmp(pt x,pt y){
    return x.val<y.val;
}

bool cmp2(node x,node y){
    return x.a[3].val-x.a[2].val<y.a[3].val-y.a[2].val;
}

int calc(int l){
    int ret; ret=0;
    vector <node> t;
    for(int i=1;i<=n;i++){
        if(x[i].a[3].id==l){
            t.push_back(x[i]);
        }
    }

    sort(t.begin(),t.end(),cmp2);
    for(int i=0;i<(t.size()-(n/2));i++){
        //cout<<t[i].a[3].val<<"->"<<t[i].a[2].val<<endl;
        ret+=t[i].a[2].val-t[i].a[3].val;
    }

    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int _; cin>>_;

    while(_--){
        cin>>n;

        int cnta,cntb,cntc; cnta=cntb=cntc=0;
        for(int i=1;i<=n;i++){
            int a,b,c; cin>>a>>b>>c;
            x[i].a[1]={a,1};
            x[i].a[2]={b,2};
            x[i].a[3]={c,3};

            sort(x[i].a+1,x[i].a+1+3,cmp);
        }

        int ans; ans=0;
        for(int i=1;i<=n;i++){
            ans+=x[i].a[3].val;

            if(x[i].a[3].id==1){
                cnta++;
            }

            if(x[i].a[3].id==2){
                cntb++;
            }

            if(x[i].a[3].id==3){
                cntc++;
            }
        }

        //cout<<ans<<endl;

        if(cnta>n/2){
            ans+=calc(1);
        }

        if(cntb>n/2){
            ans+=calc(2);
        }

        if(cntc>n/2){
            ans+=calc(3);
        }

        cout<<ans<<endl;
    }
    return 0;
}
