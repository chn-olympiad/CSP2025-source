#include <bits/stdc++.h>
using namespace std;
struct c{
    int a[4],i,b12,b13,b23;
};
int cc1(c x1,c x2){
    if(x1.i!=x2.i) return x1.i<x2.i;
    if(x1.i==1) return min(x1.b12,x1.b13)>min(x2.b12,x2.b13);
    else return 0;
}
int cc2(c x1,c x2){
    x1.i--;
    x2.i--;
    if(x1.i==0) x1.i=3;
    if(x2.i==0) x2.i=3;
    if(x1.i!=x2.i) return x1.i<x2.i;
    if(x1.i==1) return min(x1.b23,-x1.b12)>min(x2.b23,-x2.b12);
    else return 0;
}
int cc3(c x1,c x2){
    x1.i++;
    x2.i++;
    if(x1.i==4) x1.i=1;
    if(x2.i==4) x2.i=1;
    if(x1.i!=x2.i) return x1.i<x2.i;
    if(x1.i==1) return min(-x1.b23,-x1.b13)>min(-x2.b23,-x2.b13);
    else return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,ap[5]={},s=0,t;
        c a[100005]={};
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
            int imax=max(a[i].a[1],max(a[i].a[2],a[i].a[3]));
            if(imax==a[i].a[1]){
                a[i].i=1;
                ap[1]++;
            }else if(imax==a[i].a[2]){
                a[i].i=2;
                ap[2]++;
            }else{
                a[i].i=3;
                ap[3]++;
            }
            a[i].b12=a[i].a[1]-a[i].a[2];
            a[i].b13=a[i].a[1]-a[i].a[3];
            a[i].b23=a[i].a[2]-a[i].a[3];
        }
        if(ap[1]>n/2){
            t=1;
        }else if(ap[2]>n/2){
            t=2;
        }else if(ap[3]>n/2){
            t=3;
        }else t=0;
        if(t==1){
            sort(a+1,a+n+1,cc1);
            for(int i=n/2+1;i<=ap[1];i++){
                if(a[i].a[2]>a[i].a[3]) a[i].i=2;
                else a[i].i=3;
            }
        }
        else if(t==2){
            sort(a+1,a+n+1,cc2);
            for(int i=n/2+1;i<=ap[2];i++){
                if(a[i].a[1]>a[i].a[3]) a[i].i=1;
                else a[i].i=3;
            }
        }
        else if(t==3){
            sort(a+1,a+n+1,cc3);
            for(int i=n/2+1;i<=ap[3];i++){
                if(a[i].a[1]>a[i].a[2]) a[i].i=1;
                else a[i].i=2;
            }
        }
        for(int i=1;i<=n;i++){
            s+=a[i].a[a[i].i];
        }
        cout<<s<<"\n";
    }
}
