#include<bits/stdc++.h>
using namespace std;
int a[4][100005],ns[4],nns[4];int n,sum=0;
struct t{
    int a[10];
    int b[10];
}s[1000005];
bool cmp(int c,int b){
    if(ns[1]>n/2){
            return min(s[int(c)].b[2],s[b].b[3])<min(s[b].b[2],s[b].b[3]);
    }
    if(ns[2]>n/2){
            return min(s[int(c)].b[1],s[c].b[3])<min(s[b].b[1],s[b].b[3]);
    }
    if(ns[3]>n/2){
            return min(s[c].b[2],s[c].b[1])<min(s[b].b[2],s[b].b[1]);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        memset(ns,0,sizeof(ns));
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
            int ccc=max(s[i].a[1],max(s[i].a[2],s[i].a[3]));
            s[i].b[1]=ccc-s[i].a[1];
            s[i].b[2]=ccc-s[i].a[2];
            s[i].b[3]=ccc-s[i].a[3];




                        int minn=0x3f3f3f3f,date=0;
                    for(int l=1;l<=3;l++){
                        if(ns[l]<minn&&s[i].a[l]==ccc){
                            minn=ns[l];
                            date=l;
                        }
                    }
                    a[date][++ns[date]]=i;

            }



        for(int i=1;i<=3;i++){
                for(int j=1;j<=ns[i];j++){
                    sum+=s[a[i][j]].a[i];
                }
            }
        if(ns[1]<=n/2&&ns[2]<=n/2&&ns[3]<=n/2){
            cout<<sum<<endl;
            continue;
        }
        else {
                bool bb[4]={0,0,0,0};
            for(int i=1;i<=3;i++){
                if(ns[i]>n/2){
                    sort(a[i]+1,a[i]+ns[i],cmp);
                    bb[i]=1;
                }
            }
            for(int i=1;i<=3;i++){
                if(bb[i]){
                    for(int j=1;j<=ns[i]-(n/2);j++){
                        int minn=0x3f3f3f3f;
                        for(int l=1;l<=3;l++){
                            if(ns[l]<n/2){
                                minn=min(minn,s[a[i][j]].b[l]);
                            }
                        }
                        sum-=minn;
                        a[i][j]=0;
                    }
                    sort(a[i]+1,a[i]+ns[i]+1);
                    ns[i]=n/2;
                }
            }
            cout<<sum<<endl;

        }

    }
}
