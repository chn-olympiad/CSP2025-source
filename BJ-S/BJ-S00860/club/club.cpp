#include<bits/stdc++.h>
using namespace std;
int n,t;
struct xian{
    int a,b,c;
}di[100005];
struct gzc{
    int a,b,id;
};
bool operator<(const gzc a,gzc b){
    return a.b>b.b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        priority_queue<gzc> a,b,c;
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>di[i].a>>di[i].b>>di[i].c;
        }
        for(int i=1; i<=n; i++){

            if(di[i].a>=di[i].b&&di[i].a>=di[i].c){
                //    cout<<"sb";
                if(a.size()==n/2){
                    if(a.top().b<di[i].a-max(di[i].b,di[i].c)){
                        if(di[a.top().id].b>di[a.top().id].c)
                            b.push({di[a.top().id].b,di[a.top().id].b-di[a.top().id].c,a.top().id});
                        else
                            c.push({di[a.top().id].c,di[a.top().id].c-di[a.top().id].b,a.top().id});
                        a.pop();
                        a.push({di[i].a,di[i].a-max(di[i].b,di[i].c),i});
                    }
                    else{
                        if(di[i].b>di[i].c)
                            b.push({di[i].b,di[i].b-di[i].c,i});
                        else
                            c.push({di[i].c,di[i].c-di[i].b,i});
                    }
                }
                else{
                  //  cout<<"sb"<<endl;
                    a.push({di[i].a,di[i].a-max(di[i].b,di[i].c),i});
                }
            }
            else if(di[i].b>=di[i].c&&di[i].b>=di[i].a){
                   // cout<<"sb";
                if(b.size()==n/2){
                    if(b.top().b<di[i].b-max(di[i].a,di[i].c)){
                        if(di[b.top().id].a>di[b.top().id].c)
                            a.push({di[b.top().id].a,di[b.top().id].a-di[b.top().id].b,b.top().id});
                        else
                            c.push({di[b.top().id].c,di[b.top().id].b-di[b.top().id].a,b.top().id});
                        b.pop();
                        b.push({di[i].b,di[i].b-max(di[i].a,di[i].c),i});
                    }
                    else{
                        if(di[i].a>di[i].c)
                            a.push({di[i].a,di[i].a-di[i].c,i});
                        else
                            c.push({di[i].c,di[i].c-di[i].a,i});

                    }
                }
                else{
                   // cout<<"sb";
                    b.push({di[i].b,di[i].b-max(di[i].a,di[i].c),i});
                }
            }else{
                  //  cout<<"sb";
                if(c.size()==n/2){
                    if(c.top().b<di[i].c-max(di[i].b,di[i].a)){
                        if(di[c.top().id].b>di[c.top().id].a)
                            b.push({di[c.top().id].b,di[c.top().id].b-di[c.top().id].a,c.top().id});
                        else
                            a.push({di[c.top().id].a,di[c.top().id].a-di[c.top().id].b,c.top().id});
                        c.pop();
                        c.push({di[i].c,di[i].c-max(di[i].b,di[i].a),i});
                    }
                    else{
                        if(di[i].b>di[i].a)
                            b.push({di[i].b,di[i].b-di[i].a,i});
                        else
                            a.push({di[i].a,di[i].a-di[i].b,i});
                    }
                }
                else{
                    c.push({di[i].c,di[i].c-max(di[i].b,di[i].a),i});
                }
            }
        }
        int ans=0;
        while(a.size()){
            ans+=a.top().a;
            //cout<<"a"<<a.top().a<<" "<<a.top().b<<endl;
            a.pop();
        }
        while(b.size()){
            ans+=b.top().a;
            //cout<<"b"<<b.top().a<<" "<<b.top().b<<endl;
            b.pop();
        }
        while(c.size()){
            ans+=c.top().a;
            //cout<<"c"<<c.top().a<<" "<<c.top().b<<endl;
            c.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
4
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926*/
