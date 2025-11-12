#include<bits/stdc++.h>
using namespace std;
long long n,T,club[5][100005],cln[5],sum;
struct node{
    int lk[5],clb;
}a[100005];
bool cmp(node x,node y){
    return x.lk[0]>y.lk[0];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int RP=1145;RP<1145+T;RP++){
        sum=0;
        cin>>n;
        for(int i=0;i<3;i++){
            for(int j=0;j<100002;j++) club[i][j]=0;
            cln[i]=0;
        }
        for(int i=0;i<n;i++){
            cin>>a[i].lk[0]>>a[i].lk[1]>>a[i].lk[2];
        }
        if(n<=10000){
            for(int i=0;i<n;i++){
                int MaxC,Max=-1,gt,lost=-32766,mt,mw,lgt,mk;
                for(int j=0;j<3;j++){
                    if(cln[j]<n/2) gt=a[i].lk[j];
                    else{
                        for(int k=0;k<cln[j];k++){
                            for(int lo=0;lo<3;lo++) if(lost<a[club[j][k]].lk[lo]-a[club[j][k]].lk[j]&&lo!=j){
                                lost=a[club[j][k]].lk[lo]-a[club[j][k]].lk[j];
                                mt=lo;
                                mw=club[j][k];
                                mk=k;
                            }
                            lgt=lost+a[i].lk[j];
                        }
                        if(lgt>Max){
                            Max=lgt;
                            MaxC=j;
                        }
                    }
                    if(gt>Max){
                        Max=gt;
                        MaxC=j;
                    }
                }
                if(cln[MaxC]>=n/2){
                    club[mt][cln[mt]]=mw;
                    club[MaxC][mk]=i;
                    cln[mt]++;
                }
                else{
                    club[MaxC][cln[MaxC]]=i;
                    cln[MaxC]++;
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<cln[i];j++){
                    sum+=a[club[i][j]].lk[i];
                }
            }
        }
        else{
            sort(a,a+n,cmp);
            for(int i=0;i<n/2;i++){
                sum+=a[i].lk[0];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
//love wuyin,my teacher