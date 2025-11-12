#include<bits/stdc++.h>
// #define int long long
#define N 1000005
using namespace std;
int n,m,f[2][105][105][105];
struct node{
    int x,y,z;
    vector<pair<int,int>> p;
    int b[4];
}a[N];
int id[N],val[N];
struct el{
    int x,y,z,id;
    bool operator<(const el&t)const{
        if(x==t.x){
            if(y==t.y) return z<t.z;
            return y<t.y;
        }
        return x<t.x;
    }
};
struct er{
    int x,y,z,id;
    bool operator<(const er&t)const{
        if(x==t.x){
            if(y==t.y) return z>t.z;
            return y>t.y;
        }
        return x>t.x;
    }
};
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int res=0;
        map<int,int> mp;
        val[1]=val[2]=val[3]=0;
        bool subA=1,subB=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y==0&&a[i].z==0) subA=1;
            else subA=0;
            // if(a[i].y)
            // vector<pair<int,int>> p;
            a[i].p.clear();
            a[i].p.push_back({a[i].x,1});
            a[i].p.push_back({a[i].y,2});
            a[i].p.push_back({a[i].z,3});
            sort(a[i].p.begin(),a[i].p.end());
            reverse(a[i].p.begin(),a[i].p.end());
            for(int j=0;j<3;j++) a[i].b[j+1]=a[i].p[j].second;
            id[i]=a[i].b[1],val[a[i].b[1]]+=a[i].p[0].first;
            mp[a[i].b[1]]++;
        }
        if(n<=200){
            int o=1;
            memset(f,0,sizeof(f));
            for(int i=1;i<=n;i++){
                memset(f[o],0,sizeof(f[o]));
                for(int j=0;j<=n/2;j++){
                    if(j>i) break;
                    for(int k=0;k<=n/2;k++){
                        int l=(i-1)-j-k;
                        if(l<0) break;
                        if(j+1<=n/2) f[o][j+1][k][l]=max(f[o][j+1][k][l],f[o^1][j][k][l]+a[i].x);
                        if(k+1<=n/2) f[o][j][k+1][l]=max(f[o][j][k+1][l],f[o^1][j][k][l]+a[i].y);
                        if(l+1<=n/2) f[o][j][k][l+1]=max(f[o][j][k][l+1],f[o^1][j][k][l]+a[i].z);
                        res=max({res,f[o][j+1][k][l],f[o][j][k+1][l],f[o][j][k][l+1]});
                    }
                }
                memcpy(f[o^1],f[o],sizeof(f[o]));
                o^=1;
            }
            cout<<res<<"\n";
        }
        else{
            if(subA){
                vector<int> t;
                for(int i=1;i<=n;i++) t.push_back(a[i].x);
                sort(t.begin(),t.end(),greater<int>());
                int res=0;
                for(int i=1;i<=n/2;i++) res+=t[i-1];
                cout<<res<<"\n";
            }
            else{
                bool fl=1;
                for(int i=1;i<=3;i++){
                    if(mp[a[i].b[i]]>n/2){
                        fl=0;
                        break;
                    }
                }
                if(fl){
                    cout<<val[1]+val[2]+val[3]<<"\n";
                    continue;
                }
                priority_queue<el> q[4];
                for(int i=1;i<=n;i++){
                    q[id[i]].push({a[i].p[0].first,a[i].p[1].first,a[i].p[2].first,i});
                }
                for(int i=1;i<=n;i++){
                    if(mp[i]<=n/2) continue;
                    while(mp[i]>n/2){
                        auto j=q[i].top();
                        if(i==1){
                            if(a[j.id].y>=a[j.id].z&&mp[2]<n/2) mp[1]--,mp[2]++,id[j.id]=2;
                            else mp[1]--,mp[3]++,id[j.id]=3;
                        }
                        else if(i==2){
                            if(a[j.id].y>=a[j.id].z&&mp[1]<n/2) mp[2]--,mp[1]++,id[j.id]=1;
                            else mp[2]--,mp[3]++,id[j.id]=3;
                        }
                        else{
                            if(a[j.id].y>=a[j.id].z&&mp[1]<n/2) mp[3]--,mp[1]++,id[j.id]=1;
                            else mp[3]--,mp[2]++,id[j.id]=2;
                        }
                    }
                }
                int res=0;
                for(int i=1;i<=n;i++){
                    if(id[i]==1) res+=a[i].x;
                    if(id[i]==2) res+=a[i].y;
                    if(id[i]==3) res+=a[i].z; 
                }
                cout<<res<<'\n';
            }
        }
        // priority_queue<el> q[4][4];
        // priority_queue<er> q2[4][4];
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<3;j++){
        //         for(int k=0;k<3;k++) if(j^k) for(int l=0;l<3;l++) if(k!=l&&l!=j){
        //             q[j][k].push({a[i].p[j].first,a[i].p[k].first,a[i].p[l].first,i});
        //             q2[j][k].push({a[i].p[j].first,a[i].p[k].first,a[i].p[l].first,i});
        //         }
        //     }
        // }
        // for(int i=1;i<=3;i++){
        //     if(mp[i]<=n/2) continue;
        //     while(mp[i]>n/2){
        //         for(int j=0;j<3;j++){
        //             for(int k=0;k<3;k++){
        //                 while(q[j][k].size()&&id[q[j][k]].top().id]!=j) q[j][k].pop();
        //                 while(q2[j][k].size()&&id[q2[j][k].top().id]!=j) q2[j][k].pop();
        //             }
        //         }
        //         if(i==1){
        //             el tmp1,tmp2;
        //             if(q[1][0].size()) tmp1=q[1][0].top();
        //             if(q[2][0].size()) tmp2=q[2][0].top();
        //             er now=q2[0][1].top();
        //             er now2=q2[0][2].top();
        //             int res1=tmp1.y+now.x,res2=tmp2.x+now2.y;
        //             if(res1>res2)
        //             // el tmp1=q[1][0].top();
        //             // for(int j=1;j<=3;j++){
        //             //     while(q[j].size()&&id[q[j].top().id]!=j) q[j].pop();
        //             //     while(q2[j].size()&&id[q2[j].top().id]!=j) q2[j].pop();
        //             // }
        //         }
        //     }
        // }
        // priority_queue<er> q4[4],q5[4],q6[4];
        // for(int i=1;i<=n;i++){
        //     q[id[i]].push({a[i].p[0].first,a[i].p[1].first,a[i].p[2].first,i});
        //     q2[id[i]].push({a[i].p[1].first,a[i].p[0].first,a[i].p[2].first,i});
        //     q3[id[i]].push({a[i].p[2].first,a[i].p[0].first,a[i].p[1].first,i});
        //     q2[id[i]].push({a[i].p[0].first,a[i].p[1].first,a[i].p[2].first,i});
        // }
        // for(int i=1;i<=3;i++){
        //     if(mp[a[i].b[i]]<=n/2) continue;
        //     while(q2[i].size()>n/2){
        //         vector<er> tmp;
        //         for(int j=1;j<=3;j++){
        //             while(q[j].size()&&id[q[j].top().id]!=j) q[j].pop();
        //             while(q2[j].size()&&id[q2[j].top().id]!=j) q2[j].pop();
        //         }
        //         if(q[i].size()<=n/2||q2[i].size()<=n/2) break;
        //         for(int j=1;j<=3;j++) if(i!=j&&q2[j].size()) tmp.push_back(q2[j].top());
                
        //     }
        // }
    }
}