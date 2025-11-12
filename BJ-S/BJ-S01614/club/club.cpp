#include<bits/stdc++.h>
using namespace std;
int t,n;
struct yg{
    int a1=0,a2=0,a3=0,bh=0;
    int best=0;
};
bool cmp1(yg x,yg y){
    return x.a1>x.a1;
}
bool cmp2(yg x,yg y){
    return x.a2>x.a2;
}
bool cmp3(yg x,yg y){
    return x.a3>x.a3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int u=1;u<=t;u++){
        int yl1=0,yl2=0,yl3=0;
        cin>>n;
        if(n>2){
        bool f1[100005];
        bool f2[100005];
        bool f3[100005];
        int p1[100005];
        int p2[100005];
        int p3[100005];
        int ans=0;
        yg a[100005],b[100005];
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            b[i].a1=a[i].a1;
            b[i].a2=a[i].a2;
            b[i].a3=a[i].a3;
            a[i].bh=b[i].bh=i;
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++){
            p1[i]=a[i].bh;
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++){
            p2[i]=a[i].bh;
        }
        sort(a+1,a+n+1,cmp3);
        for(int i=1;i<=n;i++){
            p3[i]=a[i].bh;
        }
        for(int i=1;i<=3;i++){
            if(i==1){
                for(int o=1;o<=n/2;o++){
                    f1[o]=true;
                }
                yl1=n/2;
            }else{
                for(int j=1;j<=n;j++){
                    if(i==2){
                        if(f1[p2[j]]==false&&yl2<(n/2)){
                            f2[p2[j]]=true;
                            yl2++;
                        }else if(f1[p2[j]]==true){
                            if(b[p2[j]].a1<b[p2[j]].a2&&yl2<(n/2)){
                                f1[p2[j]]=false;
                                yl1--;
                                f2[p2[j]]=true;
                                yl2++;
                            }
                        }
                    }else{
                        if(f1[p3[j]]==false&&f2[p3[j]]==false&&yl3<(n/2)){
                            f3[p3[j]]=true;
                            yl3++;
                        }else if(f1[p3[j]]==true&&f2[p3[j]]==false&&yl3<(n/2)){
                            if(b[p3[j]].a1<b[p3[j]].a3){
                                f1[p3[j]]=false;
                                yl1--;
                                f3[p3[j]]=true;
                                yl3++;
                            }
                        }else if(f2[p3[j]]==true&&f1[p3[j]]==false&&yl3<(n/2)){
                            if(b[p3[j]].a2<b[p3[j]].a3){
                                f2[p3[j]]=false;
                                yl2--;
                                f3[p3[j]]=true;
                                yl3++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(f1[i]==true)ans+=b[i].a1;
        }
        for(int i=1;i<=n;i++){
            if(f2[i]==true)ans+=b[i].a2;
        }
        for(int i=1;i<=n;i++){
            if(f3[i]==true)ans+=b[i].a3;
        }
        cout<<ans<<"\n";
        }else{
            int x1,x2,x3,y1,y2,y3;
            cin>>x1>>x2>>x3>>y1>>y2>>y3;
            cout<<max((x1+y2),max((x1+y3),max((x2+y3),max((x2+y1),max((x3+y1),(x3+y2))))))<<"\n";
        }
    }
    return 0;
}
