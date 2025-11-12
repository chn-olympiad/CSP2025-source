#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],flagc=false,flags=false,ans=1,vis[1000];
int s[1000];
void luyong(int step,int nolu){
    if(step==n+1){
        //cout<<"at"<<endl;
        if(n-nolu>=m){
            ans=(ans+1)%998%244%353;
        }
        return;
    }
    if(n-nolu<m){
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            if(c[i]<=nolu||s[step]==0){
                //cout<<step<<" "<<c[i]<<" "<<s[step]<<" "<<i<<"nolu"<<endl;
                luyong(step+1,nolu+1);
            }else{
                //cout<<step<<" "<<c[i]<<" "<<s[step]<<" "<<i<<"lu"<<endl;
                luyong(step+1,nolu);
            }
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char nan;
        cin>>nan;
        s[i]=nan-'0';
        if(s[i]==0) flags=true;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0) flagc=true;
    }

    if(m==n){
        if(!flagc&&!flags){
            for(int i=1;i<=n;i++){
                ans=ans*i%998%244%353;
            }
            cout<<ans;
        }else{
            cout<<0;
        }
        return 0;
    }
    ans--;
    luyong(1,0);
    cout<<ans;
    return 0;
}

