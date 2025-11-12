#include<bits/stdc++.h>
using namespace std;
long long t,n,half,m[100005][5],b[100005],c[5][100005],d[100005],ml,r[5],a[5],h,l1,l2,is;
int g1(){
    for(int i=1;i<=r[h];i++){
        d[i]=(min(m[c[h][i]][h]-m[c[h][i]][l1],m[c[h][i]][h]-m[c[h][i]][l2])*100000)+c[h][i];
    }
    sort(d+1,d+r[h]+1);
    for(int i=1;i<=r[h]-half;i++){
        is=d[i]%100000;
        if(m[is][l1]>=m[is][l2]){
            a[l1]+=m[is][l1];
            a[h]-=m[is][h];
        }
        else{
            a[l2]+=m[is][l2];
            a[h]-=m[is][h];
        }
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        half=n/2;
        r[1]=0;
        a[1]=0;
        r[2]=0;
        a[2]=0;
        r[3]=0;
        a[3]=0;
        for(int i=1;i<=n;i++){
            cin>>m[i][1]>>m[i][2]>>m[i][3];
            ml=max(m[i][1],max(m[i][2],m[i][3]));
            if(ml==m[i][1]){
                b[i]=1;
                r[1]++;
                c[1][r[1]]=i;
                a[1]+=ml;
            }
            else if(ml==m[i][2]){
                b[i]=2;
                r[2]++;
                c[2][r[2]]=i;
                a[2]+=ml;
            }
            else if(ml==m[i][3]){
                b[i]=3;
                r[3]++;
                c[3][r[3]]=i;
                a[3]+=ml;
            }
        }
        if(r[1]<=half&&r[2]<=half&&r[3]<=half){
            cout<<a[1]+a[2]+a[3]<<endl;
            continue;
        }
        if(r[1]>half){
            h=1;
            l1=2;
            l2=3;
            g1();
        }
        if(r[2]>half){
            h=2;
            l1=1;
            l2=3;
            g1();
        }
        if(r[3]>half){
            h=3;
            l1=1;
            l2=2;
            g1();
        }
        cout<<a[1]+a[2]+a[3]<<endl;
    }
    return 0;
}
