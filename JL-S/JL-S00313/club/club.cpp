#include <bits/stdc++.h>
using namespace std;
int t,b[10000][10],n,cnt=0,ma=-1,f,s,th,r=0,u=0,p;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int a=1;a<=t;a++){
    cin>>n;
     for(int i=1;i<=n;i++){
     for(int j=1;j<=3;j++){
       cin>>b[i][j];
    }
 }
}
for(int a=1;a<=t;a++){
for(int i=1;i<=n;i++){
        if(n>=2){
            cnt+=ma;
            ma=-1;
        }
    for(int j=1;j<=3;j++){
        if(b[i][j]>ma){
            ma=b[i][j];
            p=j;
            if(p==1)
                f++;
            if(p==2)
                s++;
            if(p==3)
                th++;
            r=f+s+th;

            }
     }
     u+=ma;

 }
if(r/2<n/2){
    cout<<u;
}else{
for(int i=1;i<=n;i++){
 for(int j=1;j<=3;j++){
        if(f>s&&f>th){
            u=u-b[1][1];
            u=u+b[1][2];
            cout<<u;
            return 0;
        }
    }
 }
}
}

return 0;

}
