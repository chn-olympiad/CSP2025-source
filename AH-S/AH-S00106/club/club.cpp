#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,f[105][105][105],f1[205][205];
struct node{
    int x,y,z;
}s[100000];
bool cmp(node x,node y){
return x.x>y.x;}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));memset(f1,0,sizeof(f1));
        cin>>n;
        bool A=1,B=1;
        for(int i=1;i<=n;i++){
            cin>>s[i].x>>s[i].y>>s[i].z;
            if(s[i].y!=0||s[i].z!=0)A=0;
            if(s[i].z!=0)B=0;
        }
        if(A){
            int cnt=0;
            sort(s+1,s+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                cnt+=s[i].x;
            }
            cout<<cnt<<"\n";
        }
        else if(B){
            for(int i=1;i<=n;i++){
                for(int j=n/2;j>=0;j--){
                    for(int k=n/2;k>=0;k--){
                        if(j>0)f1[j][k]=max(f1[j][k],f1[j-1][k]+s[i].x);
                        if(k>0)f1[j][k]=max(f1[j][k],f1[j][k-1]+s[i].y);
                    }
                }
            }
            cout<<f1[n/2][n/2]<<"\n";
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=n/2;j>=0;j--){
                    for(int k=n/2;k>=0;k--){
                        for(int l=n/2;l>=0;l--){
                            if(j>0)f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+s[i].x);
                            if(k>0)f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+s[i].y);
                            if(l>0)f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+s[i].z);
                        }
                    }
                }
            }
            cout<<f[n/2][n/2][n/2]<<"\n";
        }

    }
}//Ren5Jie4Di4Ling5%
