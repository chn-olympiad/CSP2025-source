#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010][10];
int b[100010];
long long ans=0;
void dfs(int x,int ai,long long w,int a1,int a2,int a3){
    if(x==n){
        w+=a[x][ai];
        ans=max(ans,w);
        //cout<<"a1:"<<a1<<" a2:"<<a2<<" a3:"<<a3<<endl;
        //cout<<"ans:"<<ans<<" w:"<<w<<" x:"<<x<<endl;
        return ;
    }
    //cout<<x<<" w"<<endl;
    if(a1+1<=n/2){
//cout<<"a1:"<<a1+1<<" a2:"<<a2<<" a3:"<<a3<<endl;
        dfs(x+1,1,w+a[x][ai],a1+1,a2,a3);

    }
    if(a2+1<=n/2){
//cout<<"a1:"<<a1<<" a2:"<<a2+1<<" a3:"<<a3<<endl;
        dfs(x+1,2,w+a[x][ai],a1,a2+1,a3);

    }
    if(a3+1<=n/2){
//out<<"a1:"<<a1<<" a2:"<<a2<<" a3:"<<a3+1<<endl;
        dfs(x+1,3,w+a[x][ai],a1,a2,a3+1);

    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int flag2=0,flag3=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(j==2&&a[i][j]!=0){
                    flag2=1;
                }
                if(j==3&&a[i][j]!=0){
                    flag3=1;
                }
            }
        }
        if(flag2==0&&flag3==0){
            for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1);
            for(int i=n;i>=n/2+1;i--){
                //cout<<i<<endl;
                ans+=b[i];
            }
            cout<<ans<<endl;
            return 0;
        }
        dfs(1,1,0,1,0,0);
        dfs(1,2,0,0,1,0);
        dfs(1,3,0,0,0,1);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
