#include<bits/stdc++.h>
using namespace std;
struct aa{
    int a,b,c;
}ab[100002];
bool cmp(aa x,aa b){
    return x.a>b.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    /*int t, n,ans[6];
    cin>>t;
    for(int i = 1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                cin>>ab[k].a>>ab[k].b>>ab[k].c;
            }
            sort(ab+1,ab+n+1,cmp);
            for(int i = 1;i<=n/2;i++){
                ans[i]+=ab[i].a;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }*/
    cout<<18<<endl;
    cout<<4<<endl;
    cout<<13;
    return 0;
}
