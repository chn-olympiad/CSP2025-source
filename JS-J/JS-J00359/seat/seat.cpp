#include<bits/stdc++.h>
using namespace std;
const int N=21;
int n,m;
int s[110];
int a[N][N];
int ans;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>s[0];
    ans=s[0];
    for(int i=1;i<n*m;i++){
        cin>>s[i];
    }
    sort(s,s+n*m,cmp);
    int l=1,h=1;
    int ms=0;
    int c=0;
    for(int i=0;i<n*m;i++){
        a[l][h]=s[c];
        c++;
        if(ms==0){
            if(h+1<=m){
                h+=1;
            }else if(h+1>m){
                l+=1;
                if(ms==0){
                    ms=1;
                }else if(ms==1){
                    ms=0;
                }
            }
        }else if(ms==1){
            if(h-1>=1){
                h-=1;
            }else if(h-1<1){
                l+=1;
                if(ms==0){
                    ms=1;
                }else if(ms==1){
                    ms=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==ans){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
