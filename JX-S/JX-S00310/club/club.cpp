#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int i,j,n,t,a[10005][3],b[10005],u,v,w,c[5];
    cin>>t;
    for(i=0;i<t;i++){
            int s=0;
            u=0;
            v=0;
            w=0;
        cin>>n;
        for(j=0;j<n;j++){
                for(int r=0;r<3;r++)
            cin>>a[j][r];
        }

            int ma,mi;
        for(j=0;j<n;j++){
            ma=max(a[j][0],max(a[j][1],a[j][2]));
            mi=min(a[j][0],min(a[j][1],a[j][2]));
            s+=ma;
            if(ma==a[j][0]){
                u++;
            }
            if(ma==a[j][1]){
                v++;
            }
            if(ma==a[j][2]){
                w++;
            }
            b[j]=2*ma+mi-a[j][0]-a[j][1]-a[j][2];

        }
        ma=max(u,max(v,w));
        sort(b,b+n);
        j=0;
        while(ma>n/2){
            s=s-b[j];
            j++;
            ma--;
        }
        c[i]=s;
    }
    for(i=0;i<t;i++){
        cout<<c[i]<<endl;
    }
    return 0;
}
