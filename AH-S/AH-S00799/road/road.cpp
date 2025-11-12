#include<bits/stdc++.h>
using namespace std;
long long const N=1e4+5;
long long n,m,k;
long long maxt;
long long a[N][N];
long long u[N];
long long flag[N];
long long flagg;
vector<long long> geter;
void be(long long beg,long long now,long long num,long long depth){
    //cout<<beg<<" "<<now<<" "<<num<<"\n";
    if(depth>=2&&num<=a[beg][now]){
        maxt-=a[beg][now];
        //cout<<maxt<<" "<<beg<<" "<<now<<" "<<a[beg][now]<<"\n";
        a[beg][now]=-1;
        a[now][beg]=-1;
        return;
    }
    /*
    if(flagg=2&&beg==now){
        long long maxx=INT_MAX,num1=0,num2=0;
        for(int i=1;i<geter.size();i++)
            if(maxx<a[geter[i-1]][geter[i]])
                maxx=a[geter[i-1]][geter[i]],num1=geter[i-1],num2=geter[i];
        maxt-=a[num1][num2];
        a[num1][num2]=0x3f3f3f3f;
        cout<<maxt<<" "<<beg<<" "<<now<<"\n";
        return;
    }
    */
    for(int i=1;i<=n;i++)
        if(flag[i]!=1)
        if(a[now][i]!=-1){
            geter.push_back(i);
            flag[i]=1;
            be(beg,i,num+a[now][i],depth+1);
            flag[i]=0;
            geter.pop_back();
        }
}
long long behuan(long long beg,long long now,long long num,long long depth){
    //cout<<beg<<" "<<now<<" "<<num<<" "<<depth<<"\n";
           // cout<<"*********";
    if(depth>=3&&beg==now){
        long long maxx=-1,num1=0,num2=0;
        for(int i=1;i<geter.size();i++){
                //cout<<maxx<<" "<<num1<<" "<<num2<<"\n";
            if(maxx<a[geter[i-1]][geter[i]])
                maxx=a[geter[i-1]][geter[i]],num1=geter[i-1],num2=geter[i];
        }
        maxt-=maxx;
        a[num1][num2]=-1;
    a[num2][num1]=-1;
        //<<maxt<<" "<<beg<<" "<<now<<"\n";
        //if(beg==n-1)
        //    cout<<maxt;
        return maxt;
    }
    //for(int i=1;i<=n;i++){
    //for(int j=1;j<=n;j++)
    //        cout<<a[i][j]<<" ";
    //    cout<<"\n";
    //}
    //cout<<"a[1][2]"<<a[1][2]<<" ";
    for(int i=1;i<=n;i++){
            //cout<<"a[1][2]"<<a[1][2]<<" ";
            //cout<<now<<" "<<i<<"        ";
        if(depth<2&&i==beg)
            continue;
        if(i!=now&&a[now][i]!=-1){
            geter.push_back(i);
            flag[i]=1;
            //cout<<"******";
            behuan(beg,i,num+a[now][i],depth+1);
            flag[i]=0;
            geter.pop_back();
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    //cout<<n<<" "<<m<<" "<<k<<"\n";
    memset(a,0,sizeof a);
    for(int i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
        maxt+=w;
    }
    while(k--){
        long long t;
        cin>>t;
        for(int j=1;j<=n;j++){
            cin>>u[j];
            //a[j][j]=0;
            //cout<<u[j]<<" ";
        }
        //cout<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxt-=a[i][j],a[i][j]=min(a[i][j],u[i]+u[j]),a[j][i]=a[i][j],maxt+=a[i][j];
            //cout<<a[i][j]<<" ";
            }
            //cout<<"\n";
        }
    }
    //cout<<maxt<<"\n";
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof flag);
        flagg=1;
        flag[i]=1;
        be(i,i,0,0);
        flag[i]=0;
    }//shan bian
    long long num;
    for(int i=1;i<n;i++){
            geter.push_back(i);
        num=behuan(i,i,0,0);
        geter.pop_back();
    }
    //cout<<"****";
    cout<<num;
}
