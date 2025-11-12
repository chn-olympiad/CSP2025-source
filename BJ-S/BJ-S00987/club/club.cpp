#include <bits/stdc++.h>
using namespace std;
int t;
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n=0,a[100005][4]={};
        long long ans=0;
        bool s[100005][4]={};
        priority_queue<pair<int,int> > k[4];
        cin>>n;
        queue<int> q={};
        for(int i=0;i<n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(i>=n/2)q.push(i);
        }
        for(int i=0;i<n/2;i++){
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                s[i][1]=true;
                k[1].push({a[i][1]*-1,i});
            }
            if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                s[i][2]=true;
                k[2].push({a[i][2]*-1,i});
            }
            if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
                s[i][3]=true;
                k[3].push({a[i][3]*-1,i});
            }
        }
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                if(k[1].size()<n/2){
                    s[i][1]=true;
                    k[1].push({a[i][1]*-1,i});
                }else{
                    if(a[i][1]-min(a[i][2],a[i][3])>k[1].top().first*-1-max(a[k[1].top().second][2],a[k[1].top().second][3])){
                        s[k[1].top().second][1]=false;
                        s[i][1]=true;
                        if(k[2].size()<n/2&&a[k[1].top().second][2]>a[k[1].top().second][3]){
                            s[k[1].top().second][2]=true;
                            k[2].push({k[1].top().first,k[1].top().second});
                        }else{
                            s[k[1].top().second][3]=true;
                            k[3].push({k[1].top().first,k[1].top().second});
                        }
                        k[1].pop();
                        k[1].push({a[i][1]*-1,i});
                    }
                }
            }
            if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                if(k[2].size()<n/2){
                    s[i][2]=true;
                    k[2].push({a[i][2]*-1,i});
                }else{
                    if(a[i][2]-min(a[i][1],a[i][3])>k[2].top().first*-1-max(a[k[2].top().second][1],a[k[2].top().second][3])){
                        s[k[2].top().second][2]=false;
                        s[i][2]=true;
                        if(k[1].size()<n/2&&a[k[2].top().second][1]>a[k[2].top().second][3]){
                            s[k[2].top().second][1]=true;
                            k[1].push({k[2].top().first,k[2].top().second});
                        }else{
                            s[k[2].top().second][3]=true;
                            k[3].push({k[2].top().first,k[2].top().second});
                        }
                        k[2].pop();
                        k[2].push({a[i][2]*-1,i});
                    }
                }
            }
            if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
                if(k[3].size()<n/2){
                    s[i][3]=true;
                    k[3].push({a[i][3]*-1,i});
                }else{
                    if(a[i][3]-min(a[i][2],a[i][1])>k[3].top().first*-1-max(a[k[3].top().second][2],a[k[3].top().second][1])){
                        s[k[3].top().second][3]=false;
                        s[i][3]=true;
                        if(k[2].size()<n/2&&a[k[3].top().second][2]>a[k[3].top().second][3]){
                            s[k[3].top().second][2]=true;
                            k[2].push({k[3].top().first,k[3].top().second});
                        }else{
                            s[k[3].top().second][1]=true;
                            k[1].push({k[3].top().first,k[3].top().second});
                        }
                        k[3].pop();
                        k[3].push({a[i][3]*-1,i});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s[i][1]){
                ans+=a[i][1];
            }
            if(s[i][2]){ans+=a[i][2];}
            if(s[i][3]){ans+=a[i][3];}
        }
        cout<<ans<<endl;
    }
    return 0;
}