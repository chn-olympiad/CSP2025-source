#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a,b,c,s0,s1,s2;
int ans=0;
int cz[4][100005];
bool kmt(int a,int b){
return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
            ans=0;
            s0=s1=s2=0;
        memset(cz,0,sizeof cz);
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            if(a>=b&&a>=c){
                cz[0][s0++]=a-max(b,c);
            }else if(b>=a&&b>=c){
                cz[1][s1++]=b-max(a,c);
            }else {
                cz[2][s2++]=c-max(a,b);
            }
            ans+=max(a,max(b,c));
        }
        sort(cz[0],cz[0]+s0,kmt);
        sort(cz[1],cz[1]+s1,kmt);
        sort(cz[2],cz[2]+s2,kmt);
        while(s0>n/2){
            ans-=cz[0][--s0];
        }
        while(s1>n/2){
            ans-=cz[1][--s1];
        }
        while(s2>n/2){
            ans-=cz[2][--s2];
        }
        cout<<ans<<endl;
    }
}
