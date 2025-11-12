#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool ct[10005];
struct road{
    int u,v;
    long long w;
}sd[1000005];
struct vil{
    long long c,w[10005];
    bool fix=false;
}v[15];
bool cmp(road a,road b){
    return a.w<b.w||(a.w==b.w&&a.u<b.u)||(a.w==b.w&&a.u==b.u&&a.v<b.v);
}
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>sd[i].u>>sd[i].v>>sd[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>v[i].c;
        for(int j=1;j<=n;j++){
            cin>>v[i].w[j];
        }
    }
    sort(sd+1,sd+1+m,cmp);
    int cnt=1;
    while(cnt<n){
        int i=1;
        bool flag=false;
        while(flag==false){
            if(ct[sd[i].u]==false||ct[sd[i].v]==false){
                //cout<<"from "<<sd[i].u<<" to "<<sd[i].v<<endl;
                //cout<<"from "<<ct[sd[i].u]<<" to "<<ct[sd[i].v]<<endl;
                long long vilcost=3*1e9+10;
                int j;
                for(j=1;j<=k;j++){
                    if(v[j].fix==true){
                        vilcost=min(vilcost,v[j].w[sd[i].u]+v[j].w[sd[i].v]);
                    }
                    else{
                        vilcost=min(vilcost,v[j].w[sd[i].u]+v[j].w[sd[i].v]+v[j].c);
                    }
                }
                //cout<<"vilcost:"<<vilcost<<endl;
                //cout<<"sd[i].w:"<<sd[i].w<<endl;
                if(vilcost<=sd[i].w){
                    ans+=vilcost;
                    v[j].fix=true;
                    //cout<<"selected vilcost, fixed vil"<<j<<endl;
                }
                else{
                    ans+=sd[i].w;
                    //cout<<"selected sd[i].w"<<endl;
                }
                ct[sd[i].u]=true;
                ct[sd[i].v]=true;
                //cout<<"from "<<sd[i].u<<" to "<<sd[i].v<<endl;
                //for(int op=1;op<=n;op++){
                //    cout<<ct[i]<<' ';
                //}
                //cout<<endl;
                cnt++;
                flag=true;
            }
            else{
                while(sd[i].u==sd[i+1].u&&sd[i].v==sd[i+1].v){
                    i++;
                }
                i++;
            }
            //cout<<endl;
        }
    }
    cout<<ans;
    return 0;
}
