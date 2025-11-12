#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;
struct cs_kill{
    int x,b,c;
    bool f;
};
struct cs_kills{
    int data;
    int index;
};
struct cs_killspl{
    int team,seat;
};
int cmp1(cs_kill a){
    if(a.x>=a.b&&a.b>=a.c)return 1;
    if(a.b>=a.x&&a.x>=a.c)return 2;
    if(a.c>=a.b&&a.b>=a.x)return 3;
}
bool cmp(cs_kills a,cs_kills b){
    return a.data<b.data;
}
int main(){
freopen(".in","r",stdin);
freopen(".out","w",stdout);
int t;cin>>t;
while(t--){
    int n;cin>>n;
    long long s;
    cs_kill a[n+5];
    cs_kills maxa[n+20],maxb[n+20],maxc[n+20];
    int xa=0;
    int xb=0;
    int xc=0;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].b>>a[i].c;
        if(cmp1(a[i])==1){maxa[xa].data=a[i].x;maxa[xa]=i;xa++;}
        if(cmp1(a[i])==2){maxb[xb].data=a[i].b;maxb[xb]=i;xb++;}
        if(cmp1(a[i])==3){maxc[xc].data=a[i].c;maxc[xc]=i;xc++;}
    }
    sort(maxa,maxa+xa,cmp);
    sort(maxb,maxb+xb,cmp);
    sort(maxc,maxc+xc,cmp);
    int minpaya=N,minpayb=N,minpayc=N;
    if(xa>n/2){
        cs_killspl l;
        while(xa>n/2){
            for(int i=0;i<xa;i++){
                int minpay1=N;
                int minpayf=minpaya; 
                if(a[maxa[i].index].x>=a[maxa[i].index]&&a[maxa[i].index].x-a[maxa[i].index].c>=0){
                    minpay1=min(a[maxa[i].index].x-a[maxa[i].index].b,a[maxa[i].index].x-a[maxa[i].index].c);
                }
                minpaya=min(minpaya,minpay1);
                if(minpayf!=minpaya){
                    if(minpaya==a[maxa[i].index].x-a[maxa[i].index].b){
                        l.seat=2;
                    }
                    else l.seat=3;
                    l.team=maxa[i].index;
                }
                if(l.seat==2){
                    maxb[xb++]=a[l.team].b;maxa[xa++]=maxa[xa++]-a[l.team].x;
                }
                if(l.seat==3){
                    maxc[xc++]=a[l.team].c;maxa[xa++]=maxa[xa++]-a[l.team].x;
                }
            }
        }
    }
    if(xb>n/2){
        cs_killspl l;
        while(xb>n/2){
            for(int i=0;i<xb;i++){
                int minpay1=N;
                int minpayf=minpayb;
                if(a[maxa[i].index].b-a[maxa[i].index].x>=0&&a[maxa[i].index].x-a[maxa[i].index].c>=0){
                   minpay1=min(a[maxa[i].index].b-a[maxa[i].index].x,a[maxa[i].index].x-a[maxa[i].index].c);
                }
                minpayb=min(minpayb,minpay1);
                if(minpayf!=minpayb){
                    l.team=maxb[i].index;
                    if(minpayb==a[maxa[i].index].b-a[maxa[i].index].x){
                        l.seat=2;
                    }
                    else l.seat=3;
                }
            }
            if(l.seat==2){
                maxa[xa++]=a[l.team].x;maxb[xb++]=maxb[xb++]-a[l.team].b;
            }
            if(l.seat==3){
                maxc[xc++]=a[l.team].c;maxb[xb++]=maxb[xb++]-a[l.team].b;
            }
        }
    }
    if(xc>n/2){
        cs_killspl l;
        while(xc>n/2){
            for(int i=0;i<xc;i++){
                int minpay1=N;
                int minpayf=minpayc;
                if(a[maxa[i].index].c-a[maxa[i].index].x>=0&&a[maxa[i].index].c-a[maxa[i].index].b>=0){
                   minpay1=min(a[maxa[i].index].c-a[maxa[i].index].x,a[maxa[i].index].x-a[maxa[i].index].b);
                }
                minpayc=min(minpayc,minpay1);
                if(minpayf!=minpayc){
                    l.team=maxc[i].index;
                    if(minpayc==a[maxa[i].index].c-a[maxa[i].index].x){
                        l.seat=2;
                    }
                    else l.seat=3;
                }
            }
            if(l.seat==2){
                maxa[xc++]=a[l.team].x;maxc[xc++]=maxc[xc++]-a[l.team].c;
            }
            if(l.seat==3){
                maxb[xb++]=a[l.team].b;maxc[xc++]=maxc[xc++]-a[l.team].c;
            }
        }
    }
    for(int i=0,j=0,k=0;i<xa||j<xb||k<xc;i++;j++;k++){
        s=s+maxa[i]+maxb[j]+maxc[k];
    }
    s=s+minpaya+minpayb+minpayc;
    cout<<s<<endl;
    }
}
return 0;
} 
