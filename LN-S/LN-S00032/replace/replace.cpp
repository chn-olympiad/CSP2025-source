#include <bits/stdc++.h>
using namespace std;
struct node{
    string a,b;
}used[200500],q[200500],ac[200500];
int n,m;

node findd(string x,string y){
    int l=0,f=0;
    for(int i=0;i<x.size();i++){
        if(x[i]!=y[i]){
            f=i;
            break;
        }
    }
    for(int i=x.size()-1;i>=0;i--){
        if(x[i]!=y[i]){
            l=i;
            break;
        }
    }
    string c,d;
    for(int i=f;i<=l;i++){
        c+=x[i],d+=y[i];
    }
    return {c,d};
}

bool finding(string x1,string y1,string x2,string y2){
    int sizee=x1.size()-y1.size()+1;
    int f=0,l=0;
    for(int i=0;i<sizee;i++){
        bool ff=1;
        for(int j=0;j<y1.size();j++){
            if(x1[i+j]!=y1[j]||x2[i+j]!=y2[j]){
                ff=0;
                break;
            }
        }
        if(ff){
            return 1;
        }
    }
    return 0;
}

bool same(string x,string y){
    for(int i=0;i<x.size();i++){
        if(x[i]!=y[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> used[i].a >> used[i].b;
        ac[i]=findd(used[i].a,used[i].b);
    }
    for(int i=1;i<=m;i++){
        cin >> q[i].a >> q[i].b;

    }
    for(int i=1;i<=m;i++){
            int ans=0;
        node ak=findd(q[i].a,q[i].b);
        for(int j=1;j<=n;j++){
            if(used[j].a.size()>q[i].a.size()){
                continue;
            }
            if(same(ak.a,ac[j].a)&&same(ak.b,ac[j].b)&&finding(q[i].a,used[j].a,q[i].b,used[j].b)){
                ans++;
            }
        }cout << ans << endl;

    }
    return 0;
}
/*

pray god that this works(((
50 50 50 50 50 50 50 50 50 50
50 50 50 50 50 50 50 50 50 50
50 50 50 50 50 50 50 50 50 50
50 50 50 50 50 50 50 50 50 50
50 50 50 50 50 50 50 50 50 50

*/
