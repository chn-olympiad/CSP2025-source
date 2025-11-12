#include<bits/stdc++.h>
using namespace std;
struct st{
    int a[3];
};
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    int n;
    struct st sd[100000];
    for(int i=0;i<t;i++){
        int mx;
        int o[100000],os=0;
        int e[100000],es=0;
        int s[100000],ss=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            cin>>sd[j].a[0]>>sd[j].a[1]>>sd[j].a[2];
            mx=max(sd[j].a[0],sd[j].a[1]);
            mx=max(mx,sd[j].a[2]);
            if(mx==sd[j].a[0]){
                o[os]=j;
                os++;
            }else if(mx==sd[j].a[1]){
                e[es]=j;
                es++;
            }else{
                s[ss]=j;
                ss++;
            }
        }
        int mn,mnx=0,mny;
        if(os>n/2){
            while(os>n/2){
                mnx=0;
                mn=sd[o[0]].a[0]-max(sd[o[0]].a[1],sd[o[0]].a[2]);
                mny=max(sd[o[0]].a[1],sd[o[0]].a[2]);
                for(int j=1;j<os;j++){
                    if((sd[o[j]].a[0]-max(sd[o[j]].a[1],sd[o[j]].a[2]))<mn){
                        mn=sd[o[j]].a[0]-max(sd[o[j]].a[1],sd[o[j]].a[2]);
                        mnx=j;
                        mny=max(sd[o[j]].a[1],sd[o[j]].a[2]);
                    }
                }
                if(mny==sd[o[mnx]].a[1]){
                    e[es]=mnx;
                    es++;
                }else{
                    s[ss]=mnx;
                    ss++;
                }
                o[mnx]=0;
                sort(o,o+os,cmp);
                os--;

            }
        }
        if(es>n/2){
            while(es>n/2){
                mnx=0;
                mn=sd[e[0]].a[1]-max(sd[e[0]].a[0],sd[e[0]].a[2]);
                mny=max(sd[e[0]].a[0],sd[e[0]].a[2]);
                for(int j=1;j<es;j++){
                    if((sd[e[j]].a[1]-max(sd[e[j]].a[0],sd[e[j]].a[2]))<mn){
                        mn=max(sd[e[j]].a[0],sd[e[j]].a[2]);
                        mnx=j;
                        mny=max(sd[e[j]].a[0],sd[e[j]].a[2]);
                    }
                }
                if(mny==sd[e[mnx]].a[0]){
                    o[os]=mnx;
                    os++;
                }else{
                    s[ss]=mnx;
                    ss++;
                }
                e[mnx]=0;
                sort(e,e+es,cmp);
                es--;

            }
        }
        if(ss>n/2){
            while(ss>n/2){
                    mnx=0;
                mn=sd[s[0]].a[2]-max(sd[s[0]].a[1],sd[s[0]].a[0]);
                mny=max(sd[s[0]].a[1],sd[s[0]].a[0]);
                for(int j=1;j<ss;j++){
                    if((sd[s[j]].a[2]-max(sd[s[j]].a[1],sd[s[j]].a[0]))<mn){
                        mn=max(sd[s[j]].a[1],sd[s[j]].a[0]);
                        mnx=j;
                        mny=max(sd[s[j]].a[1],sd[s[j]].a[0]);
                    }
                }
                if(mny==sd[s[mnx]].a[1]){
                    e[es]=mnx;
                    es++;
                }else{
                    o[os]=mnx;
                    os++;
                }
                s[mnx]=0;
                sort(s,s+ss,cmp);
                ss--;

            }
        }
        int oh=0,eh=0,sh=0;
        for(int j=0;j<os;j++){
            oh+=sd[o[j]].a[0];
        }
        for(int j=0;j<es;j++){
            eh+=sd[e[j]].a[1];
        }
        for(int j=0;j<ss;j++){
            sh+=sd[s[j]].a[2];
        }
        printf("%d",oh+eh+sh);
    }
    return 0;
}
