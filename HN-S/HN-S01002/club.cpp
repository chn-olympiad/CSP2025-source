#include<bits/stdc++.h>
using namespace std;
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
#define N 200900
struct fvv{
    int a;
    int b;
    int c;
}f[N];
struct fvv1{
    int id;
    int sum1;
    int sum2;
    bool operator<(const fvv1 tmp)const{
        return sum1-sum2>tmp.sum1-tmp.sum2;
    }
};
priority_queue<fvv1 >q1,q2,q3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        int n=read();
        for(int i=1;i<=n;i++){
            f[i].a=read();
            f[i].b=read();
            f[i].c=read();
        }
        int ans=0;
        int m=n/2;
        for(int i=1;i<=n;i++){
            int maxi=max(f[i].a,max(f[i].b,f[i].c));
            int mini=min(f[i].a,min(f[i].b,f[i].c));
            int mid=f[i].a;
            if(f[i].a!=maxi&&f[i].a!=mini)mid=f[i].a;
            else if(f[i].b!=maxi&&f[i].b!=mini)mid=f[i].b;
            else if(f[i].c!=maxi&&f[i].c!=mini)mid=f[i].c;
            if(maxi==f[i].a){
                if(q1.size()<m){
                    q1.push((fvv1){i,maxi,mid});
                    ans+=maxi;
                }
                else{
                    int maxlast=q1.top().sum1-q1.top().sum2;
                    int maxnow=maxi-mid;
                    if(maxlast>=maxnow){
                        ans+=mid;
                    }
                    else{
                        ans-=q1.top().sum1;
                        ans+=q1.top().sum2;
                        q1.pop();
                        ans+=maxi;
                        q1.push((fvv1){i,maxi,mid});
                    }
                }
            }
            else if(maxi==f[i].b){
                if(q2.size()<m){
                    q2.push((fvv1){i,maxi,mid});
                    ans+=maxi;
                }
                else{
                    int maxlast=q2.top().sum1-q2.top().sum2;
                    int maxnow=maxi-mid;
                    if(maxlast>=maxnow){
                        ans+=mid;
                    }
                    else{
                        ans-=q2.top().sum1;
                        ans+=q2.top().sum2;
                        q2.pop();
                        q2.push((fvv1){i,maxi,mid});
                        ans+=maxi;
                    }
                }
            }
            else if(maxi==f[i].c){
                if(q3.size()<m){
                    q3.push((fvv1){i,maxi,mid});
                    ans+=maxi;
                }
                else{
                    int maxlast=q3.top().sum1-q3.top().sum2;
                    int maxnow=maxi-mid;
                    if(maxlast>=maxnow){
                        ans+=mid;
                    }
                    else{
                        ans-=q3.top().sum1;
                        ans+=q3.top().sum2;
                        q3.pop();
                        q3.push((fvv1){i,maxi,mid});
                        ans+=maxi;
                    }
                }
            }
        }
        cout<<ans<<'\n';
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
        while(!q3.empty())q3.pop();
        for(int i=1;i<=n;i++){
            f[i].a=0;
            f[i].b=0;
            f[i].c=0;
        }
    }
    
}