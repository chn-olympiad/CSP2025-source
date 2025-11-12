#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long n=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        n=(n<<3)+(n<<1)+(ch^48);
        ch=getchar();
    }
    return n*f;
}
const int inf=INT_MAX;
long long ans=0;
const int N=1e4+5;
const int M=1e6+5;
long long mp[N][N];
long long rd[M];
bool nrd[N][N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) mp[i][j]=inf;
    }
    for(int i=1;i<=n;i++){
        int u,v,w;
        u=read(),v=read(),w=read();
        mp[u][v]=mp[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        int c=read();
        for(int j=1;j<=n;j++){
            rd[j]=read();
        }
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                mp[j][k]=min(mp[j][k],c+rd[j]+rd[k]);
                mp[k][j]=mp[j][k];
            }
        }
    }
    priority_queue<int,vector<int>,greater<int>>q;
    long long pl=1;
    long long maxi=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            mp[i][j]=mp[j][i]=min(mp[i][j],mp[j][i]);
     //       cout<<mp[i][j]<<" ";
        }
   //     cout<<endl;
    }
    //cout<<endl;
    long long last=mp[pl][1];
    for(int i=1;i<=n;i++){
        q.push(mp[pl][i]);
        if(mp[pl][i] < last){
            maxi=i;
            last=mp[pl][i];
        }

        mp[pl][i]=inf;
    }
    nrd[pl][maxi]=nrd[maxi][pl]=1;
    pl=maxi;

    long long cnt=0;
    while(!q.empty()&&cnt<n-1){
        int k=q.top();
        ans+=k;
        q.pop();
        cnt++;
        //cout<<pl<<" "<<k<<endl;
        last=mp[pl][1];
        for(int i=1;i<=n;i++){
            if(nrd[pl][i]) continue;
            q.push(mp[pl][i]);

            if(mp[pl][i]<last){
                maxi=i;
                last=mp[pl][i];
            }
            mp[pl][i]=inf;
        }
        nrd[pl][maxi]=nrd[maxi][pl]=1;
        pl=maxi;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
