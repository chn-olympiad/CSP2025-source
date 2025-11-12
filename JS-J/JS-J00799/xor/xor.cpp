#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,lop,cheak,bns;
struct qwer{
    int x;
    int y;
} ans[5000005];
bool cmp(qwer a,qwer b){
    if(a.y==b.y){
        return a.y-a.x+1<b.y-b.x+1;
    }
    return a.y<b.y;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //return 0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            x=a[l];
            for(int i=l;i<r;i++){
                x=x^a[i+1];
            }
            if(x==k){
                lop++;
                //cout<<l<<" "<<r<<endl;
                ans[lop].x=l;
                ans[lop].y=r;
            }
        }
    }
    sort(ans+1,ans+lop+1,cmp);
    //for(int i=1;i<=lop;i++){
    //    cout<<ans[i].x<<" "<<ans[i].y<<endl;
    //}
    cheak=0;
    for(int i=1;i<=lop;i++){
        if(ans[i].x<=cheak&&ans[i].y>=cheak){
            //cout<<ans[i].x<<" "<<ans[i].y<<endl;
        }else{
            bns++;
            cheak=ans[i].y;
        }
    }
    cout<<bns;
    cout<<endl;
    return 0;
}
