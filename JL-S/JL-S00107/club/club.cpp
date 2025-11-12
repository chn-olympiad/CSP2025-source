#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int pa[MAXN],pb[MAXN],pc[MAXN];
int xa_[MAXN],xb_[MAXN],xc_[MAXN];
int xap,xbp,xcp,*xa,*xb,*xc;
bool sort_func1(int x,int y){
    return pa[x]-max(pb[x],pc[x])<pa[y]-max(pb[y],pc[y]);
}
bool sort_func2(int x,int y){
    return pb[x]-max(pa[x],pc[x])<pb[y]-max(pa[y],pc[y]);
}
bool sort_func3(int x,int y){
    return pc[x]-max(pb[x],pa[x])<pc[y]-max(pb[y],pa[y]);
}
void inserts(int x,int i){
    if(i==0){
        if(pb[xa[0]]>pc[xa[0]]){
            xb[xbp]=xa[0];
            xbp++;
            xa[0]=x;
        }else{
            xc[xcp]=xa[0];
            xcp++;
            xa[0]=x;
        }
    }else if(i==1){
        if(pa[xb[0]]>pc[xb[0]]){
            xa[xap]=xb[0];
            xap++;
            xb[0]=x;
        }else{
            xc[xcp]=xb[0];
            xcp++;
            xb[0]=x;
        }
    }else{
        if(pb[xc[0]]>pa[xc[0]]){
            xb[xbp]=xc[0];
            xbp++;
            xc[0]=x;
        }else{
            xa[xap]=xc[0];
            xap++;
            xc[0]=x;
        }
    }
}
int choise(int x){
    if(pa[x]>pb[x]){
        if(pc[x]>pa[x])return 2;
        else return 0;
    }else if(pb[x]>pc[x]){
        if(pa[x]>pb[x])return 0;
        else return 1;
    }else{
        if(pb[x]>pc[x])return 1;
        else return 2;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        xap=xbp=xcp=0;
        xa=&xa_[0];xb=&xb_[0];xc=&xc_[0];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>pa[i]>>pb[i]>>pc[i];
        }
        bool flag=true,flag1;
        for(int i=0;i<n;i++){
            flag1=false;
            int ch=choise(i);
            if(ch==0){
                if(xap<(n>>1)){
                    xa[xap]=i;
                    xap++;
                }else flag1=true;
            }else if(ch==1){
                if(xbp<(n>>1)){
                    xb[xbp]=i;
                    xbp++;
                }else flag1=true;
            }else{
                if(xcp<(n>>1)){
                    xc[xcp]=i;
                    xcp++;
                }else flag1=true;
            }
            if(not flag1)flag=true;
            if(flag1){
                if(flag){
                    stable_sort(xa,xa+xap,sort_func1);
                    stable_sort(xb,xb+xbp,sort_func2);
                    stable_sort(xc,xc+xcp,sort_func3);
                    flag=false;
                }
                inserts(i,ch);
                stable_sort(xa,xa+xap,sort_func1);
                stable_sort(xb,xb+xbp,sort_func2);
                stable_sort(xc,xc+xcp,sort_func3);
            }
        }
        int ans=0;
        for(int i=0;i<xap;i++)ans+=pa[xa[i]];
        for(int i=0;i<xbp;i++)ans+=pb[xb[i]];
        for(int i=0;i<xcp;i++)ans+=pc[xc[i]];
        cout<<ans<<endl;
    }
    return 0;
}
