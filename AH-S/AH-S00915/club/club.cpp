#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,nn;
struct node{
    int l[5];
    int m,p;
    int il[5];
    int minn;
}k[100005];
int n[5],idx,maxn;
bool cmp(node x,node y){
    return x.minn<y.minn;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>nn;
        n[1]=n[2]=n[3]=maxn=0;
        for(int i=1;i<=nn;i++){
            cin>>k[i].l[1]>>k[i].l[2]>>k[i].l[3];
            k[i].m=max(k[i].l[1],max(k[i].l[2],k[i].l[3]));
            k[i].il[1]=(k[i].l[1]==k[i].m);
            k[i].il[2]=(k[i].l[2]==k[i].m);
            k[i].il[3]=(k[i].l[3]==k[i].m);
            k[i].p=k[i].il[1]+k[i].il[2]+k[i].il[3];
            n[1]+=k[i].il[1],n[2]+=k[i].il[2],n[3]+=k[i].il[3];
            maxn+=k[i].m;
        }
        idx=0;
        int p,q;
        if(n[1]>nn/2) idx=1,p=2,q=3;
        else if(n[2]>nn/2) idx=2,p=1,q=3;
        else if(n[3]>nn/2) idx=3,p=1,q=2;
        if(idx==0){
            cout<<maxn<<endl;
        }else{
            for(int i=1;i<=nn;i++){
                if(k[i].il[idx]==0) k[i].minn=0x3f3f3f3f;
                else k[i].minn=min(k[i].l[idx]-k[i].l[p],k[i].l[idx]-k[i].l[q]);
            }
            sort(k+1,k+1+nn,cmp);
            for(int i=1;i<=nn;i++){
                if(k[i].il[idx]==0) continue;
                if(k[i].p>1){
                    n[idx]--;
                    continue;
                }
                if(n[idx]<=nn/2) break;
                n[idx]-=1;
                maxn=maxn+max(k[i].l[p],k[i].l[q])-k[i].m;
            }
            cout<<maxn<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
