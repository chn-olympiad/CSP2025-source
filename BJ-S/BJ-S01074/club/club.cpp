#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int a,b,c;
}e[100005];
node check(int i){
    int t1,t2,t3;
    if(e[i].a>=e[i].b&&e[i].a>=e[i].c){
        t1=1;
        if(e[i].b>=e[i].c){
            t2=2;
            t3=3;
        }else{
            t2=3;
            t3=2;
        }
    }
    else if(e[i].b>=e[i].c&&e[i].b>=e[i].a){
        t1=2;
        if(e[i].a>=e[i].c){
            t2=1;
            t3=3;
        }else{
            t2=3;
            t3=1;
        }
    }else{
        t1=3;
        if(e[i].a>=e[i].b){
            t2=1;
            t3=2;
        }else{
            t2=2;
            t3=1;
        }
    }
    node x;
    x.a=t1;
    x.b=t2;
    x.c=t3;
    return x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>e[i].a>>e[i].b>>e[i].c;
        }
        priority_queue<pair<int,int> > q1;
        priority_queue<pair<int,int> > q2;
        priority_queue<pair<int,int> > q3;
        for(int i=1;i<=n;i++){
            node xx=check(i);
            if(xx.a==1){
                if(xx.b==2)
                    q1.push({-e[i].a+e[i].b,i});
                else
                    q1.push({-e[i].a+e[i].c,i});
            }else if(xx.a==2){
                if(xx.b==1)
                    q2.push({-e[i].b+e[i].a,i});
                else
                    q2.push({-e[i].b+e[i].c,i});
            }else{
                if(xx.b==1)
                    q3.push({-e[i].c+e[i].a,i});
                else
                    q3.push({-e[i].c+e[i].b,i});
            }
            node x;
            int q;
            bool f=0;
            if(q1.size()>n/2){
                q=q1.top().second;
                q1.pop();
                f=1;
            }else if(q2.size()>n/2){
                q=q2.top().second;
                //cout<<"b**";
                q2.pop();
                f=1;
            }else if(q3.size()>n/2){
                q=q3.top().second;
                q3.pop();
                f=1;
            }
            if(f){
                x=check(q);
                bool f2=1;
                if(x.b==1&&q1.size()<n/2){
                    if(x.c==2)
                        q1.push({-e[q].a+e[q].b,q});
                    else
                        q1.push({-e[q].a+e[q].c,q});
                    f2=0;
                }else if(x.b==2&&q2.size()<n/2){
                    if(x.c==1)
                        q2.push({-e[q].b+e[q].a,q});
                    else
                        q2.push({-e[q].b+e[q].c,q});
                    f2=0;
                }else if(x.b==3&&q3.size()<=n/2){
                    if(x.c==1)
                        q3.push({-e[q].c+e[q].a,q});
                    else
                        q3.push({-e[q].c+e[q].b,q});
                    f2=0;
                }
                if(f2){
                    if(x.c==1&&q1.size()<n/2){
                        q1.push({-1e9,q});
                    }else if(x.c==2&&q2.size()<n/2){
                        q2.push({-1e9,q});
                    }else if(x.c==3&&q3.size()<n/2){
                        q3.push({-1e9,q});
                    }
                }
            }
            //cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].c<<"\n";
        }
        long long ans=0;
        //cout<<"\na\n";
        while(!q1.empty()){
            ans+=(e[q1.top().second].a);
            //cout<<q1.top().second<<" "<<e[q1.top().second].a<<"\n";
            q1.pop();
        }
        //cout<<"\n"<<ans;
        //cout<<"\nb\n";
        while(!q2.empty()){
            ans+=(e[q2.top().second].b);
            //cout<<q2.top().second<<" "<<e[q2.top().first].b<<"\n";
            q2.pop();
        }
        //cout<<"\n"<<ans;
        //cout<<"\nc\n";
        while(!q3.empty()){
            ans+=(e[q3.top().second].c);
            //cout<<q3.top().second<<" "<<e[q3.top().first].c<<"\n";
            q3.pop();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
