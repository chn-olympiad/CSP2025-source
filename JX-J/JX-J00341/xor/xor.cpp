#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000000],ans=0,dj=0;
struct but{
   int tou,wei;
   bool qy=true;
}cs[9000000];
bool cmp(but a,but b){
    return a.wei<b.wei;
}
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            dj++;
            cs[dj].tou=i;
            cs[dj].wei=i;
        }
    }
    for(int i=1;i<=n;i++){
        int sum=a[i];
        for(int j=i+1;j<=n;j++){
            sum=(sum^a[j]);
            if(sum==k){
                dj++;
                cs[dj].tou=i;
                cs[dj].wei=j;
                j=n+1;
            }
        }
    }

    sort(cs+1,cs+dj+1,cmp);

    if(dj==2&&cs[1].wei>=cs[2].tou){
        cout<<1;
        return 0;
    }
    ans=dj;
    int k1=cs[1].wei;
    for(int i=2;i<=dj;i++){
        if(cs[i].tou<=k1){
            cs[i].qy=false;
            ans--;
        }else{
            k1=cs[i].wei;
        }
    }

    cout<<ans;
    return 0;
}
