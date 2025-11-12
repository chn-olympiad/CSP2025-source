#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5;
int a[N][3];
struct st{
    int a,n;
    bool operator<(const st& ot)const{
        return ot.a<a;
    }
};
priority_queue<st> a0,a1,a2;
int maxa(int i,int ans){
    if(ans==a[i][0]){
        return 0;
    }
    else if(ans==a[i][1]){
        return 1;
    }
    else{
        return 2;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long  ans=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&a[j][0]);
            scanf("%d",&a[j][1]);
            scanf("%d",&a[j][2]);
        }
        while(!a0.empty()){
          a0.pop();
        }
        while(!a1.empty()){
          a1.pop();
        }
        while(!a2.empty()){
          a2.pop();
        }
        for(int j=0;j<n;j++){
            int maxn=max(a[j][0],max(a[j][1],a[j][2]));
            int m=maxa(j,maxn);
            if(m==0){
                if(a0.size()<n/2){
                    ans+=maxn;
                    a0.push({a[j][0],j});
                }
                else{
                    int b=max(a[j][1],a[j][2]);
                    int c=max(a[a0.top().n][1],a[a0.top().n][2]);
                    if(b<a[j][0]+c-a[a0.top().n][0]){
                        int d=maxa(a0.top().n,c);
                        ans+=a[j][0]+c-a[a0.top().n][0];
                        if(d==1){
                            a1.push({a[a0.top().n][1],a0.top().n});
                        }
                        else{
                            a2.push({a[a0.top().n][2],a0.top().n});
                        }
                        a0.pop();
                        a0.push({a[j][0],j});

                    }
                    else{
                        int d=maxa(j,b);
                        ans+=b;
                        if(d==1){
                            a1.push({a[j][1],j});
                        }
                        else{
                            a2.push({a[j][2],j});
                        }
                    }
                }
            }
            else if(m==1){
                if(a1.size()<n/2){
                    ans+=maxn;
                    a1.push({a[j][1],j});
                }
                else{
                    int b=max(a[j][0],a[j][2]);
                    int c=max(a[a1.top().n][0],a[a1.top().n][2]);
                    if(b<a[j][1]+c-a[a1.top().n][1]){
                        int d=maxa(a1.top().n,c);
                        ans+=a[j][1]+c-a[a1.top().n][1];
                        if(d==0){
                            a0.push({a[a1.top().n][0],a1.top().n});
                        }
                        else{
                            a2.push({a[a1.top().n][2],a1.top().n});
                        }
                        a1.pop();
                        a1.push({a[j][1],j});

                    }
                    else{
                        int d=maxa(j,b);
                        ans+=b;
                        if(d==0){
                            a0.push({a[j][0],j});
                        }
                        else{
                            a2.push({a[j][2],j});
                        }
                    }
                }
            }
            else{
                if(a2.size()<n/2){
                    ans+=maxn;
                    a2.push({a[j][2],j});
                }
                else{
                    int b=max(a[j][0],a[j][1]);
                    int c=max(a[a1.top().n][0],a[a1.top().n][1]);
                    if(b<a[j][2]+c-a[a2.top().n][2]){
                        int d=maxa(a2.top().n,c);
                        ans+=a[j][2]+c-a[a2.top().n][2];
                        if(d==0){
                            a0.push({a[a2.top().n][0],a2.top().n});
                        }
                        else{
                            a1.push({a[a2.top().n][1],a2.top().n});
                        }
                        a2.pop();
                        a2.push({a[j][2],j});

                    }
                    else{
                        int d=maxa(j,b);
                        ans+=b;
                        if(d==0){
                            a0.push({a[j][0],j});
                        }
                        else{
                            a1.push({a[j][1],j});
                        }
                    }
                }
            }
        }
        printf("%d ",ans);
    }
    return 0;
}
