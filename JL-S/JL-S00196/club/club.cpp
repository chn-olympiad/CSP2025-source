#include<bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+1;
int t,n,b[N],cnt1,cnt2,cnt3;
struct node{
    int a,b,c;
}a[N];
bool cmp(node x,node y){
    if(x.a==y.a&&x.b==y.b) return x.c<y.c;
    if(x.a==y.a) return x.b<y.b;
    return x.a<y.a;
}
priority_queue<PII,vector<PII >,greater<PII > >q12,q13,q21,q23,q31,q32;
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
    return x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            a[i].a=read();
            a[i].b=read();
            a[i].c=read();
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c) b[i]=1,cnt1++;
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) b[i]=2,cnt2++;
            else if(a[i].c>=a[i].a&&a[i].c>=a[i].b) b[i]=3,cnt3++;
        }
        for(int i=1;i<=n;i++){
            if(b[i]==1){
                q12.push({a[i].a-a[i].b,i});
                q13.push({a[i].a-a[i].c,i});
            }
            else if(b[i]==2){
                q21.push({a[i].b-a[i].a,i});
                q23.push({a[i].b-a[i].c,i});
            }
            else if(b[i]==3){
                q31.push({a[i].c-a[i].a,i});
                q32.push({a[i].c-a[i].b,i});
            }
        }
        bool boo=0;
        while(!boo){
            boo=1;
            if(cnt1>n/2){
                boo=0;
                while(cnt1>n/2){
                    PII u=q12.top(),v=q13.top();
                    while(b[u.se]!=1){
                        q12.pop();
                        if(!q12.size()) break;
                        u=q12.top();
                    }
                    while(b[v.se]!=1){
                        q13.pop();
                        if(!q13.size()) break;
                        v=q13.top();
                    }
                    if(!q12.size()&&!q13.size()) break;
                    cnt1--;
                    if(!q13.size()){
                        q12.pop();
                        q23.push({a[u.se].b-a[u.se].c,u.se});
                        cnt2++;
                        b[u.se]=2;
                    }
                    else if(!q12.size()){
                        q13.pop();
                        q32.push({a[v.se].c-a[v.se].b,v.se});
                        cnt3++;
                        b[v.se]=3;
                    }
                    else if(u.fi<v.fi){
                        q12.pop();
                        q23.push({a[u.se].b-a[u.se].c,u.se});
                        cnt2++;
                        b[u.se]=2;
                    }
                    else{
                        q13.pop();
                        q32.push({a[v.se].c-a[v.se].b,v.se});
                        cnt3++;
                        b[v.se]=3;
                    }
                }
            }
            if(cnt2>n/2){
                boo=0;
                while(cnt2>n/2){
                    PII u=q21.top(),v=q23.top();
                    while(b[u.se]!=2){
                        q21.pop();
                        if(!q21.size()) break;
                        u=q21.top();
                    }
                    while(b[v.se]!=2){
                        q23.pop();
                        if(!q23.size()) break;
                        v=q23.top();
                    }
                    if(!q21.size()&&!q23.size()) break;
                    cnt2--;
                    if(!q23.size()){
                        q21.pop();
                        q13.push({a[u.se].a-a[u.se].c,u.se});
                        cnt1++;
                        b[u.se]=1;
                    }
                    else if(!q21.size()){
                        q23.pop();
                        q31.push({a[v.se].c-a[v.se].a,v.se});
                        cnt3++;
                        b[v.se]=3;
                    }
                    else if(u.fi<v.fi){
                        q21.pop();
                        q13.push({a[u.se].a-a[u.se].c,u.se});
                        cnt1++;
                        b[u.se]=1;
                    }
                    else{
                        q23.pop();
                        q31.push({a[v.se].c-a[v.se].a,v.se});
                        cnt3++;
                        b[v.se]=3;
                    }
                }
            }
            if(cnt3>n/2){
                boo=0;
                while(cnt3>n/2){
                    PII u=q31.top(),v=q32.top();
                    while(b[u.se]!=3){
                        q31.pop();
                        if(!q31.size()) break;
                        u=q31.top();
                    }
                    while(b[v.se]!=3){
                        q32.pop();
                        if(!q32.size()) break;
                        v=q32.top();
                    }
                    if(!q31.size()&&!q32.size()) break;
                    cnt3--;
                    if(!q32.size()){
                        q31.pop();
                        q12.push({a[u.se].a-a[u.se].b,u.se});
                        cnt1++;
                        b[u.se]=1;
                    }
                    else if(!q31.size()){
                        q32.pop();
                        q21.push({a[v.se].b-a[v.se].a,v.se});
                        cnt2++;
                        b[v.se]=2;
                    }
                    else if(u.fi<v.fi){
                        q31.pop();
                        q12.push({a[u.se].a-a[u.se].b,u.se});
                        cnt1++;
                        b[u.se]=1;
                    }
                    else{
                        q32.pop();
                        q21.push({a[v.se].b-a[v.se].a,v.se});
                        cnt2++;
                        b[v.se]=2;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(b[i]==1) ans+=a[i].a;
            if(b[i]==2) ans+=a[i].b;
            if(b[i]==3) ans+=a[i].c;
        }
        cout<<ans<<endl;
        while(q12.size()) q12.pop();
        while(q13.size()) q13.pop();
        while(q21.size()) q21.pop();
        while(q23.size()) q23.pop();
        while(q31.size()) q31.pop();
        while(q32.size()) q32.pop();
    }
}
