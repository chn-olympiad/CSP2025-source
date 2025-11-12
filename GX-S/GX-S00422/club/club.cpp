#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N][6],b[N];
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int x=0,y=0,z=0;
        for (int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int xp=1;
            for (int j=1;j<=3;j++){
                if (a[i][j]>a[i][xp]){
                    xp=j;
                }
            }
            int d;

            if (xp==1){
                x++;
                d=a[i][1]-max(a[i][2],a[i][3]);
            }
            else if (xp==2){
                y++;
                d=a[i][2]-max(a[i][1],a[i][3]);
            }
            else{
                z++;
                d=a[i][3]-max(a[i][1],a[i][2]);
            }
            a[i][4]=xp;
            a[i][5]=d;
        }
        int ans=0;
        if (x<=n/2&&y<=n/2&&z<=n/2){
            for (int i=1;i<=n;i++){
                ans+=a[i][a[i][4]];
            }
            cout<<ans<<endl;
            continue;
        }
        int k=1;
        if (x>n/2){
            for (int i=1;i<=n;i++){
                if (a[i][4]==1){
                    b[k]=a[i][5];
                    k++;
                }
            }
            sort(b+1,b+k);
            k--;
            int u=k-n/2+1,v=1;
            int p=b[u];
            while (b[u]!=p){
                u++;
                v++;
            }
            if (b[k-n/2+1+v]==b[p]){
                v++;
            }
            int f=0;
            for (int i=1;i<=n;i++){
                if (a[i][4]!=1){
                    ans+=a[i][a[i][4]];
                }
                else{
                    if (a[i][5]>p){
                        ans+=a[i][1];
                    }
                    else if (a[i][5]==p && f<v){
                        ans+=a[i][1];
                        f++;
                    }
                    else{
                        ans+=(a[i][1]-a[i][5]);
                    }
                }
            }
        }
        else if (y>n/2){
            for (int i=1;i<=n;i++){
                if (a[i][4]==2){
                    b[k]=a[i][5];
                    k++;
                }
            }
            sort(b+1,b+k);
            k--;
            int u=k-n/2+1,v=1;
            int p=b[u];
            while (b[u]!=p){
                u++;
                v++;
            }
            if (b[k-n/2+1+v]==p){
                v++;
            }
            int f=0;
            for (int i=1;i<=n;i++){
                if (a[i][4]!=2){
                    ans+=a[i][a[i][4]];
                }
                else{
                    if (a[i][5]>p){
                        ans+=a[i][2];
                    }
                    else if (a[i][5]==p && f<v){
                        ans+=a[i][2];
                        f++;
                    }
                    else{
                        ans+=(a[i][2]-a[i][5]);
                    }
                }
            }
        }
        else{
            for (int i=1;i<=n;i++){
                if (a[i][4]==3){
                    b[k]=a[i][5];
                    k++;
                }
            }
            sort(b+1,b+k);
            k--;
            int u=k-n/2+1,v=1;
            int p=b[u];
            while (b[u]!=p){
                u++;
                v++;
            }
            if (b[k-n/2+1+v]==b[p]){
                v++;
            }
            int f=0;
            for (int i=1;i<=n;i++){
                if (a[i][4]!=3){
                    ans+=a[i][a[i][4]];
                }
                else{
                    if (a[i][5]>p){
                        ans+=a[i][3];
                    }
                    else if (a[i][5]==p && f<v){
                        ans+=a[i][3];
                        f++;
                    }
                    else{
                        ans+=(a[i][3]-a[i][5]);
                    }
                }
            }
        }
        cout<<ans<<endl;

        /*
        for (int i=1;i<=n;i++){
            for (int j=1;j<=5;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<x<<" "<<y<<" "<<z;
        */
    }
    return 0;
}
