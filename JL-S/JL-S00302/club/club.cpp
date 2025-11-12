#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100005],b[100005],c[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    LL n,k;
    deque<long long>h;
    cin>>k;
    while(k--){
        LL n,m;
        cin>>n;
        LL i=1;
        m=n;
    while(m--){
        cin>>a[i][1]>>b[2]>>c[3];
        i++;}
        LL ans=0;
        if(n=2){
           ans=max(a[1][1]+a[2][3],ans);
           ans=max(a[1][1]+a[2][2],ans);
           ans=max(a[1][2]+a[2][1],ans);
           ans=max(a[1][2]+a[2][3],ans);
           ans=max(a[1][3]+a[2][1],ans);
           ans=max(a[1][3]+a[2][2],ans);


        }
        if(n>2){

    for(i=1;i<=n;i++){
        if(a[i]>b[i]){
            if(a[i]<c[i]){
                ans+=c[i];
            }
            else {
                ans+=a[i];
            }
        }
        else{
            if(b[i]<c[i]){
                ans+=c[i];
            }
            else{
                ans+=b[i];
            }
        }
    }
}
        cout<<ans<<endl;




    }

fclose(stdin);
    fclose(stdout);
  return 0;
    }



