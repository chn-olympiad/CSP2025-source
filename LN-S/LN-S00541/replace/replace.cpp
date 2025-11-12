#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    string x;
    string y;
};
node a[100005];
node find(string x,string y){
    int s=-1,e=0,len=x.size();
    for(int i=0;i<len;i++){
        if(x[i]!=y[i]){
            if(s!=-1){
                e=i;
            }else{
                s=i;
                e=i;
            }
        }
    }
    return {x.substr(s,e-s+1),y.substr(s,e-s+1)};
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        a[i]=find(x,y);
    }
    while(q--){
        int ans=0;
        string x,y;
        cin>>x>>y;
        node d=find(x,y);
        for(int i=1;i<=n;i++){
            if(d.x==a[i].x&&d.y==a[i].y){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
