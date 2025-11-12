#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[5][100005];
int q=0,w=0,e=0;
int ans=0;
int y;
int v[500000000];
void ej(int n){
    for(int i=0;i<=n;i++){
        v[i]=0;
    }
    return ;
}
void sot(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(max(a[1][j],max(a[2][j],a[3][j]))<max(a[1][j+1],max(a[2][j+1],a[3][j+1]))){
                int q=a[1][j],w=a[2][j],e=a[3][j],r=a[4][j];
                a[1][j]=a[1][j+1];
                a[2][j]=a[2][j+1];
                a[3][j]=a[3][j+1];
                a[4][j]=a[4][j+1];
                a[1][j+1]=q;
                a[2][j+1]=w;
                a[3][j+1]=e;
                a[4][j+1]=r;
            }
        }
    }
}
void s(int i){
    int mx=0,mxi=0;
    bool d=false,f=false,g=false;
    if(q>=n/2){
        d=true;
    }
    if(w>=n/2){
        f=true;
    }
    if(e>=n/2){
        g=true;
    }
    for(int j=1;j<=3;j++){
        if((j==1&&d)||(j==2&&f)||(j==3&&g)){
            continue;
        }
        if(a[j][i]>mx){
            mx=a[j][i];
            mxi=j;
        }else if(a[j][i]==mx){
            if(mxi==1){
                if(j==2){
                    if(q>w){
                        mxi=j;
                    }
                }else{
                    if(q>e){
                        mxi=j;
                    }
                }
            }else{
                if(w>e){
                    mxi=j;
                }
            }
        }
    }
    if(mxi==1){
        q++;
    }else if(mxi==2){
        w++;
    }else{
        e++;
    }
    ans+=mx;
    return;
}

void dfs(int q,int w,int e,int ans,int i){
    if(i==n){
        v[y]=ans;
        y++;
        return;
    }
    if(q<n/2){
        if(w<n/2){
            if(e<n/2){
                dfs(q+1,w,e,ans+a[1][i],i+1);
                dfs(q,w+1,e,ans+a[2][i],i+1);
                dfs(q,w,e+1,ans+a[3][i],i+1);
            }else{
                dfs(q+1,w,e,ans+a[1][i],i+1);
                dfs(q,w+1,e,ans+a[2][i],i+1);
            }
        }else{
            if(e<n/2){
                dfs(q+1,w,e,ans+a[1][i],i+1);
                dfs(q,w,e+1,ans+a[3][i],i+1);
            }else{
                dfs(q+1,w,e,ans+a[1][i],i+1);
            }
        }
    }else{
        if(w<n/2){
            if(e<n/2){
                dfs(q,w+1,e,ans+a[2][i],i+1);
                dfs(q,w,e+1,ans+a[3][i],i+1);
            }else{
                dfs(q,w+1,e,ans+a[2][i],i+1);
            }
        }else{
            if(e<n/2){
                dfs(q,w,e+1,ans+a[3][i],i+1);
            }
        }
    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            a[4][i]=i;
        }
        if(n<=10){
           dfs(0,0,0,0,0);
           sort(v,v+y);
           cout<<v[y-1]<<endl;
           ej(y);
        }else{
        sot();
        ans=0;
        q=0;
        w=0;
        e=0;
        for(int i=0;i<n;i++){
            s(i);
        }
        cout<<ans<<endl;
        }
    }
    return 0;
}