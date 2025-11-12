#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N];
struct qj{
    int st;
    int ed;
}qj[2000000];
bool cmp1(struct qj x,struct qj y){
    return x.st<y.st;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sj=0,t=0;
    for(int i=1;i<=n;i++){
        for(int l=1,r=l+i-1;r<=n;l++,r++){
            sj=a[l];
            for(int x=l+1;x<=r;x++){
                sj^=a[x];
            }
            if(sj==k){
                t++;
                qj[t].st=l;
                qj[t].ed=r;
            }
        }
    }
    sort(qj+1,qj+t+1,cmp1);
    int posl=qj[1].st,posr=qj[1].ed;
    int pxs=1;
    for(int i=2;i<=t;i++){
        if(qj[i].st>posr){
            pxs++;
            posl=qj[i].st;
            posr=qj[i].ed;
        }else if(qj[i].st<=posr&&qj[i].st>=posl&&(qj[i].ed-qj[i].st+1)<=(posr-posl+1)){
            posl=qj[i].st;
            posr=qj[i].ed;
        }
    }
    cout<<pxs;
    return 0;
}
