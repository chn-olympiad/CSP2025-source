#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>
#include<iomanip>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<stack>
#define ll long long
using namespace std;
ll T;
ll n;
ll k[100005][8];
vector<ll> a[8];
ll ans;
bool cmp(ll x,ll y){
    return k[x][4]<k[y][4];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        for(int i=1;i<=4;i++){
            while(!a[i].empty()){
                a[i].pop_back();
            }
        }
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>k[i][1]>>k[i][2]>>k[i][3];
            ll pos=max(k[i][1],max(k[i][2],k[i][3]));
            ans+=pos;
            if(k[i][1]==pos){
                a[1].push_back(i);
            }else if(k[i][2]==pos){
                a[2].push_back(i);
            }else{
                a[3].push_back(i);
            }
        }
        for(ll i=1;i<=3;i++){
            if(a[i].size()>(n/2)){
                for(ll j=0;j<a[i].size();j++){
                    if(i==1){
                        k[a[i][j]][4]=(k[a[i][j]][i]-max(k[a[i][j]][2],k[a[i][j]][3]));
                    }else if(i==2){
                        k[a[i][j]][4]=(k[a[i][j]][i]-max(k[a[i][j]][1],k[a[i][j]][3]));
                    }else{
                        k[a[i][j]][4]=(k[a[i][j]][i]-max(k[a[i][j]][1],k[a[i][j]][2]));
                    }
                }
                sort(a[i].begin(),a[i].end(),cmp);
                ll lr=0,cnt=a[i].size();
                while(cnt>(n/2)){
                    ans-=k[a[i][lr]][4];
                    lr++;
                    cnt--;
                }
                break;
            }
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
