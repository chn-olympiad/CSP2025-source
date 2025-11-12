#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
};
node mp[100010];
bool cmp(node a,node b){
    return a.a>b.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>mp[i].a>>mp[i].b>>mp[i].c;
        }
        sort(mp+1,mp+n+1,cmp);
        int cnt=0;
        for(int i=1;i<=n/2;i++){
            cnt+=mp[i].a;
        }
        cout<<cnt<<endl;
    }
    
}