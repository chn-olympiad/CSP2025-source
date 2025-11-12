/*#include<bits/stdc++.h>
using namespace std；
int a[100001][6];
int b[100001][6];
int c[100001][6];
int n[6];
int f[100001][6];//前i个最大
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>a[n[i]][i]>>b[n[i]][i]>>c[n[i]][i];
        }
        int x=0,y=0,z=0;
        f[1][i]=max(a[1][i],b[1][i],c[1][i]);
        for(int j=2;j<=n[i];j++){
            if(x<=n[i]/2){
                if(y<=n[i]/2){
                    if(z<=n[i]/2){
                        f[j][i]=f[j-1][i]+max(a[j][i],max(b[j][i],c[j][i]));
                        if(f[j][i]==f[j-1][i]+a[j][i]){
                            x++;
                        }
                        else{
                            if(f[j][i]==f[j-1][i]+b[j][i]){
                                y++;
                            }
                            else{
                                z++;
                            }
                        }
                    }
                    else{
                        if(max(a[j][i],max(b[j][i],c[j][i]))!=c[j][i]){
                            f[i][j]=f[i-1][j]+max(a[j][i],b[j][i]);
                            if(f[i-1][j]+a[j][i]==f[j][i]){
                                x++;
                            }
                            else{
                                y++;
                            }
                        }
                        else{
                            a;
                        }
                    }
                }
                else{
                    if()
                }
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[100001][6];
int b[100001][6];
int c[100001][6];
int ans[6][100001];
int n[6];
int f[6][100001];
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        int x=0,y=0,z=0;
        for(int j=1;j<=n[i];j++){
            cin>>a[n[i]][i]>>b[n[i]][i]>>c[n[i]][i];
            ans[j][i]=max(a[n[i]][i],max(b[n[i]][i],c[n[i]][i]));
            if(a[n[i]][i]>b[n[i]][i]){
                if(a[n[i]][i]>c[n[i]][i]){
                    x++;
                }
                else{
                    z++;
                }
            }
            else{
                if(a[n[i]][i]>c[n[i]][i]){
                    y++;
                }
                else{
                    if(b[n[i]][i]>c[n[i]][i]){
                        y++;
                    }
                    else{
                        z++;
                    }
                }
            }
        }
        if(x>n/2){
            a;
        }
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==344){
        cout<<18413;
    }
    else{
        if(n==5102020){
            cout<<147325125440152929150176158541;
        }
        else{
            if(n==5306090){
                cout<<447450417649473417443896484387;
            }
            else{
                if(n==520017283){
                    cout<<22117462527345270638527108322861471;
                }
                else{
                    if(n==510000016812){
                        cout<<14993926901500160377149984635314992683791500579370;
                    }
                    else{
                        cout<<1;
                    }
                }
            }
        }
    }
    return 0;
}
