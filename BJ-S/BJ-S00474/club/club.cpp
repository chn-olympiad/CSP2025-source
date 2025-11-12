#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n,v[N];
struct node{
    long long val;
    int x,y;
    bool operator<(const node &B)const{
        return B.val>val;
    }
};
long long d[N][4];
priority_queue<node>b1;
priority_queue<node>b2;
priority_queue<node>b3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        long long ans=0,a,b,c,c1=0,c2=0,c3=0;
        for(int i=1;i<=n;++i){
            cin>>a>>b>>c;
            d[i][1]=a;
            d[i][2]=b;
            d[i][3]=c;
            if(a>=b&&a>=c){
                ans+=a;
                ++c1;
                v[i]=1;
                b1.push({-a+b,i,2});
                b1.push({-a+c,i,3});
            }
            else if(b>=a&&b>=c){
                ans+=b;
                ++c2;
                v[i]=2;
                b2.push({-b+a,i,1});
                b2.push({-b+c,i,3});
            }
            else{
                ans+=c;
                ++c3;
                v[i]=3;
                b3.push({-c+a,i,1});
                b3.push({-c+b,i,2});
            }
        }
        for(int i=1;i<=2;++i){
            while(c1>n/2){
                long long val=b1.top().val;
                int x=b1.top().x,y=b1.top().y;
                b1.pop();
                if(v[x]!=1) continue;
                --c1;
                ans+=val;
                v[x]=y;
                if(y==2){
                    ++c2;
                    b2.push({-d[x][2]+d[x][3],x,3});
                }
                if(y==3){
                    ++c3;
                    b3.push({-d[x][3]+d[x][2],x,2});
                }
            }
            while(c2>n/2){
                long long val=b2.top().val;
                int x=b2.top().x,y=b2.top().y;
                b2.pop();
                if(v[x]!=2) continue;
                --c2;
                ans+=val;
                v[x]=y;
                if(y==1){
                    ++c1;
                    b1.push({-d[x][1]+d[x][3],x,3});
                }
                if(y==3){
                    ++c3;
                    b3.push({-d[x][3]+d[x][1],x,1});
                }
            }
            while(c3>n/2){
                long long val=b3.top().val;
                int x=b3.top().x,y=b3.top().y;
                b3.pop();
                if(v[x]!=3) continue;
                --c3;
                ans+=val;
                v[x]=y;
                if(y==1){
                    ++c1;
                    b1.push({-d[x][1]+d[x][2],x,2});
                }
                if(y==2){
                    ++c2;
                    b2.push({-d[x][2]+d[x][1],x,1});
                }
            }
        }
        cout<<ans<<"\n";
        while(!b1.empty()) b1.pop();
        while(!b2.empty()) b2.pop();
        while(!b3.empty()) b3.pop();
    }
    return 0;
}
