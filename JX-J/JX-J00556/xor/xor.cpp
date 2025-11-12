#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],p=0,ans=0,rt[500001],lt[500001],bj[500001];
bool ch(int ck1,int ck2){
    int lt1,lt2,rt1,rt2;
    lt1=lt[ck1];
    lt2=lt[ck2];
    rt1=rt[ck1];
    rt2=rt[ck2];
    if(lt1>rt2 and lt1>lt2){
        bj[ck1]=1;
        bj[ck2]=1;
        return 1;
    }
    else if(lt2>rt1 and lt2>lt1){
        bj[ck1]=1;
        bj[ck2]=1;
        return 1;
    }
    else{
        bj[ck1]=0;
        return 0;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            long long s=a[i];
            if(i!=j){
                for(int h=i+1;h<=j;h++){
                    s=(s^a[k]);
                }
            }
            if(s==k){
                p++;
                lt[p]=i;
                rt[p]=j;
            }
        }
    }
    if(p==1){
        cout<<1;
    }
    else{
        for(int i=1;i<=p;i++){
            for(int j=i+1;j<=p;j++){
                ch(i,j);
            }
        }
    }
    for(int i=1;i<=p;p++){
        if(bj[i]==1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
