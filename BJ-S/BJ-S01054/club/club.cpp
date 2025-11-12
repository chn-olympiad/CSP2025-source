#include<bits/stdc++.h>
#define N 1000001
using namespace std;
struct per{
    int id;
    long long a,b,c;
}p[N];
struct per1{
    int id;
    long long a,b,c;
}p1[N];
struct per2{
    int id;
    long long a,b,c;
}p2[N];
struct per3{
    int id;
    long long a,b,c;
}p3[N];
bool operator <(per1 x,per1 y){
    return min(abs(x.a-x.b),abs(x.a-x.c))>min(abs(y.a-y.b),abs(y.a-y.c));
}
bool operator <(per2 x,per2 y){
    return min(abs(x.b-x.a),abs(x.b-x.c))>min(abs(y.b-y.a),abs(y.b-x.c));
}
bool operator <(per3 x,per3 y){
    return min(abs(x.c-x.a),abs(x.c-x.b))>min(abs(y.c-y.a),abs(y.c-y.b));
}
priority_queue<per1>q1;
priority_queue<per2>q2;
priority_queue<per3>q3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
            p[i].id=i;
            p1[i].a=p[i].a;p1[i].b=p[i].b;p1[i].c=p[i].c;
            p1[i].id=i;
            p2[i].a=p[i].a;p2[i].b=p[i].b;p2[i].c=p[i].c;
            p2[i].id=i;
            p3[i].a=p[i].a;p3[i].b=p[i].b;p3[i].c=p[i].c;
            p3[i].id=i;
        }
        while(!q1.empty()){
            q1.pop();
        }
        while(!q2.empty()){
            q2.pop();
        }
        while(!q3.empty()){
            q3.pop();
        }
        for(int i=1;i<=n;i++){
            long long maxx=max(p[i].a,max(p[i].b,p[i].c));
            if(maxx==p[i].a){
                q1.push(p1[i]);
                if(q1.size()>n/2){
                    per1 tp=q1.top();
                    q1.pop();
                    if(tp.a-tp.b<=tp.a-tp.c){
                        q2.push(p2[tp.id]);
                    }
                    else{
                        q3.push(p3[tp.id]);
                    }
                    if(q2.size()>n/2){
                        per2 tp2;
                        tp2=q2.top();
                        q2.pop();
                        q3.push(p3[tp2.id]);
                    }
                    if(q3.size()>n/2){
                        per3 tp3;
                        tp3=q3.top();
                        q3.pop();
                        q2.push(p2[tp3.id]);
                    }
                }
            }
            else if(maxx==p[i].b){
                q2.push(p2[i]);
                if(q2.size()>n/2){
                    per2 tp=q2.top();
                    q2.pop();
                    if(tp.b-tp.a<=tp.b-tp.c){
                        q1.push(p1[tp.id]);
                    }
                    else{
                        q3.push(p3[tp.id]);
                    }
                    if(q1.size()>n/2){
                        per1 tp1;
                        tp1=q1.top();
                        q1.pop();
                        q3.push(p3[tp1.id]);
                    }
                    if(q3.size()>n/2){
                        per3 tp3;
                        tp3=q3.top();
                        q3.pop();
                        q1.push(p1[tp3.id]);
                    }
                }

            }
            else if(maxx==p[i].c){
                q3.push(p3[i]);
                if(q3.size()>n/2){
                    per3 tp=q3.top();
                    q3.pop();
                    if(tp.c-tp.b<=tp.c-tp.a){
                        q2.push(p2[tp.id]);
                    }
                    else{
                        q1.push(p1[tp.id]);
                    }
                    if(q2.size()>n/2){
                        per2 tp2;
                        tp2=q2.top();
                        q2.pop();
                        q1.push(p1[tp2.id]);
                    }
                    if(q1.size()>n/2){
                        per1 tp1;
                        tp1=q1.top();
                        q1.pop();
                        q2.push(p2[tp1.id]);
                    }
                }
            }
        }
        long long ans=0;
        while(!q1.empty()){
            ans+=q1.top().a;
            q1.pop();
        }
        while(!q2.empty()){
            ans+=q2.top().b;
            q2.pop();
        }
        while(!q3.empty()){
            ans+=q3.top().c;
            q3.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
