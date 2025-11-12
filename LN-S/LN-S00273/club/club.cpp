#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
int n,ans;
struct node{ int a,b,c; }a[N];
priority_queue<pair<int,int> >q1,q2,q3;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=read();
    while(T--){
        n=read();
        ans=0;
        for(int i=1;i<=n;i++){
            a[i].a=read();
            a[i].b=read();
            a[i].c=read();
        }
        for(int i=1;i<=n;i++){
            if(a[i].a>=a[i].b && a[i].a>=a[i].c){
                if((int)q1.size()<(n/2)) q1.push({max(a[i].b,a[i].c)-a[i].a,i});
                else{
                    int now=max(a[i].b,a[i].c)-a[i].a;
                    if(q1.top().first>now){
                        int cur=q1.top().second;
                        if(a[cur].b>a[cur].c) q2.push({a[cur].c-a[cur].b,cur});
                        else if(a[cur].c>a[cur].b) q3.push({a[cur].b-a[cur].c,cur});
                        else {
                            if(q2.size()<=q3.size()) q2.push({0,cur});
                            else q3.push({0,cur});
                        }
                        q1.pop();
                        q1.push({now,i});
                    }
                    else{
                        int cur=i;
                        if(a[cur].b>a[cur].c) q2.push({a[cur].c-a[cur].b,cur});
                        else if(a[cur].c>a[cur].b) q3.push({a[cur].b-a[cur].c,cur});
                        else {
                            if(q2.size()<=q3.size()) q2.push({0,cur});
                            else q3.push({0,cur});
                        }                        
                    }
                }
            }
            else if(a[i].b>=a[i].a && a[i].b>=a[i].c){

                if((int)q2.size()<(n/2)) q2.push({max(a[i].a,a[i].c)-a[i].b,i});
                else{
                    int now=max(a[i].a,a[i].c)-a[i].b;
                    if(q2.top().first>now){
                        int cur=q2.top().second;
                        if(a[cur].a>a[cur].c) q1.push({a[cur].c-a[cur].a,cur});
                        else if(a[cur].c>a[cur].a) q3.push({a[cur].a-a[cur].c,cur});
                        else {
                            if(q1.size()<=q3.size()) q1.push({0,cur});
                            else q3.push({0,cur});
                        }
                        q2.pop();
                        q2.push({now,i});
                    }
                    else{
                        int cur=i;
                        if(a[cur].a>a[cur].c) q1.push({a[cur].c-a[cur].a,cur});
                        else if(a[cur].c>a[cur].a) q3.push({a[cur].a-a[cur].c,cur});
                        else {
                            if(q1.size()<=q3.size()) q1.push({0,cur});
                            else q3.push({0,cur});
                        }                    
                    }
                }

            }
            else{
                if((int)q3.size()<(n/2)) q3.push({max(a[i].a,a[i].b)-a[i].c,i});
                else{
                    int now=max(a[i].a,a[i].b)-a[i].c;
                    if(q3.top().first>now){
                        int cur=q3.top().second;
                        if(a[cur].a>a[cur].b) q1.push({a[cur].b-a[cur].a,cur});
                        else if(a[cur].b>a[cur].a) q2.push({a[cur].a-a[cur].b,cur});
                        else {
                            if(q1.size()<=q2.size()) q1.push({0,cur});
                            else q2.push({0,cur});
                        }
                        q3.pop();
                        q3.push({now,i});
                    }
                    else{
                        int cur=i;
                        if(a[cur].a>a[cur].b) q1.push({a[cur].b-a[cur].a,cur});
                        else if(a[cur].b>a[cur].a) q2.push({a[cur].a-a[cur].b,cur});
                        else {
                            if(q1.size()<=q2.size()) q1.push({0,cur});
                            else q2.push({0,cur});
                        }                    
                    }
                }
            }
        }
        while(!q1.empty()){
            ans+=a[q1.top().second].a;
            q1.pop();
        }
        while(!q2.empty()){
            ans+=a[q2.top().second].b;
            q2.pop();
        }     
        while(!q3.empty()){
            ans+=a[q3.top().second].c;
            q3.pop();
        }   
        cout<<ans<<'\n';
    }
    return 0;
}