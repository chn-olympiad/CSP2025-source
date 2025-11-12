#include <bits/stdc++.h>
using namespace std;

int t,n,cnt_b,cnt_c,cnt_d;

struct node{
    int v1,v2,v3,id,houxuan1,houxuan2;
}a[100005],b[100005],c[100005],d[100005];

bool cmp_b(node x,node y){
    if(x.houxuan1==2){
        if(y.houxuan1==2){
            if(x.v2>y.v2 && x.v1>y.v1){
                return x.v1-y.v1>x.v2-y.v2;
            }else if(x.v2<y.v2 && x.v1<y.v1){
                return y.v1-x.v1<y.v2-x.v2;
            }
        }else{
            if(x.v2>y.v3 && x.v1>y.v1){
                return x.v1-y.v1>x.v2-y.v3;
            }else if(x.v2<y.v3 && x.v1<y.v1){
                return y.v1-x.v1<y.v3-x.v2;
            }
        }
    }else{
        if(y.houxuan1==2){
            if(x.v3>y.v2 && x.v1>y.v1){
                return x.v1-y.v1>x.v3-y.v2;
            }else if(x.v3<y.v2 && x.v1<y.v1){
                return y.v1-x.v1<y.v2-x.v3;
            }
        }else{
            if(x.v3>y.v3 && x.v1>y.v1){
                return x.v1-y.v1>x.v3-y.v3;
            }else if(x.v3<y.v3 && x.v1<y.v1){
                return y.v1-x.v1<y.v3-x.v3;
            }
        }
    }
    return x.v1>y.v1;
}

bool cmp_c(node x,node y){
    if(x.houxuan1==1){
        if(y.houxuan1==1){
            if(x.v1>y.v1 && x.v2>y.v2){
                return x.v2-y.v2>x.v1-y.v1;
            }else if(x.v1<y.v1 && x.v2<y.v2){
                return y.v2-x.v2<y.v1-x.v1;
            }
        }else{
            if(x.v1>y.v3 && x.v2>y.v2){
                return x.v2-y.v2>x.v1-y.v3;
            }else if(x.v1<y.v3 && x.v2<y.v2){
                return y.v2-x.v2<y.v3-x.v1;
            }
        }
    }else{
        if(y.houxuan1==1){
            if(x.v3>y.v1 && x.v2>y.v2){
                return x.v2-y.v2>x.v3-y.v1;
            }else if(x.v3<y.v1 && x.v2<y.v2){
                return y.v2-x.v2<y.v1-x.v3;
            }
        }else{
            if(x.v3>y.v3 && x.v2>y.v2){
                return x.v2-y.v2>x.v3-y.v3;
            }else if(x.v3<y.v3 && x.v2<y.v2){
                return y.v2-x.v2<y.v3-x.v3;
            }
        }
    }
    return x.v2>y.v2;
}

bool cmp_d(node x,node y){
    if(x.houxuan1==1){//x=1
        if(y.houxuan1==1){//y=1
            if(x.v1>y.v1 && x.v3>y.v3){
                return x.v3-y.v3>x.v1-y.v1;
            }else if(x.v1<y.v1 && x.v3<y.v3){
                return y.v3-x.v3<y.v1-x.v1;
            }
        }else{//y=2
            if(x.v1>y.v2 && x.v3>y.v3){
                return x.v3-y.v3>x.v1-y.v2;
            }else if(x.v1<y.v2 && x.v3<y.v3){
                return y.v3-x.v3<y.v2-x.v1;
            }
        }
    }else{//x=2
        if(y.houxuan1==1){
            if(x.v2>y.v1 && x.v3>y.v3){
                return x.v3-y.v3>x.v2-y.v1;
            }else if(x.v2<y.v1 && x.v3<y.v3){
                return y.v3-x.v3<y.v1-x.v2;
            }
        }else{//y=2
            if(x.v2>y.v2 && x.v3>y.v3){
                return x.v3-y.v3>x.v2-y.v2;
            }else if(x.v2<y.v2 && x.v3<y.v3){
                return y.v3-x.v3<y.v2-x.v2;
            }
        }
    }
    return x.v3>y.v3;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        cnt_b=0,cnt_c=0,cnt_d=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].v1>>a[i].v2>>a[i].v3;
            a[i].id=i;
        }
        for(int i=1;i<=n;i++){
            int maxt_i=max(a[i].v1,max(a[i].v2,a[i].v3));
            if(maxt_i==a[i].v1){
                a[i].houxuan1=(a[i].v2>=a[i].v3 ? 2 : 3);
                a[i].houxuan2=(a[i].v2<a[i].v3 ? 2 : 3);
                b[++cnt_b]=a[i];
            }else if(maxt_i==a[i].v2){
                a[i].houxuan1=(a[i].v1>=a[i].v3 ? 1 : 3);
                a[i].houxuan2=(a[i].v1<a[i].v3 ? 1 : 3);
                c[++cnt_c]=a[i];
            }else{
                a[i].houxuan1=(a[i].v1>=a[i].v2 ? 1 : 2);
                a[i].houxuan2=(a[i].v1<a[i].v2 ? 1 : 2);
                d[++cnt_d]=a[i];
            }
        }

        if(cnt_b>n/2){
            sort(b+1,b+cnt_b+1,cmp_b);
            for(int i=cnt_b;i>=n/2+1;i--){
                if(b[i].houxuan1==2){
                    c[++cnt_c]=b[i];
                }else{
                    d[++cnt_d]=b[i];
                }
                cnt_b--;
            }
        }
        if(cnt_c>n/2){
            sort(c+1,c+cnt_c+1,cmp_c);
            for(int i=cnt_c;i>=n/2+1;i--){
                if(c[i].houxuan1==1){
                    b[++cnt_b]=c[i];
                }else{
                    d[++cnt_d]=c[i];
                }
                cnt_c--;
            }
        }
        if(cnt_d>n/2){
            sort(d+1,d+cnt_d+1,cmp_d);
            for(int i=cnt_d;i>=n/2+1;i--){
                if(d[i].houxuan1==1){
                    b[++cnt_b]=d[i];
                }else{
                    c[++cnt_c]=d[i];
                }
                cnt_d--;
            }
        }
        int ans=0;
        for(int i=1;i<=cnt_b;i++){
            ans+=b[i].v1;
        }
        for(int i=1;i<=cnt_c;i++){
            ans+=c[i].v2;
        }
        for(int i=1;i<=cnt_d;i++){
            ans+=d[i].v3;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
