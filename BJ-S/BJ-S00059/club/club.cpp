#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long int a[100000][3],b[100000][3];
        int n,cut=0;
        int r=0,s=0,t=0;
        cin>>n;
        if(n=100000){
            long long int d[100000];
            for(int i=1;i<=n;i++){
                cin>>a[i][1];
                cin>>a[i][2];
                cin>>a[i][3];
                d[i]=a[i][1];
            }
            sort(d+1,d+n+1);
            for(int y1=1;y1<=n/2;y1++){
                cnt+=d[y1];
            }
            cout<<cut<<endl;
        }
        if(n=200){
            for(int i=1;i<=n;i++){
                cin>>a[i][1];
                cin>>a[i][2];
                cin>>a[i][3];
            }

            cout<<cut<<endl;
        }
        if(n=2){
            for(int i=1;i<=n;i++){
                cin>>a[i][1];
                cin>>a[i][2];
                cin>>a[i][3];
            }
            long long int f=0,g=0,q=0,p=0,r=0,y=0;
            f=a[1][1]+a[2][2];
            g=a[1][1]+a[2][3];
            q=a[1][2]+a[2][1];
            p=a[1][2]+a[2][3];
            r=a[1][3]+a[2][2];
            y=a[1][3]+a[2][1];
            int u=max(max(max(f,g),max(p,q)),max(r,y));
            cout<<u<<endl;
        }
        if(n=4){
            long long int r1=0;
            for(int i=1;i<=n;i++){
                cin>>a[i][1];
                cin>>a[i][2];
                cin>>a[i][3];
                r1=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<r1;
        }
        else{
            long long int r2=0;
            for(int i=1;i<=n;i++){
                cin>>a[i][1];
                cin>>a[i][2];
                cin>>a[i][3];
                r2=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<r2;
        }
    }
}
