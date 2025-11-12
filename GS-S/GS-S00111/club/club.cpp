#include<bits/stdc++.h>
using namespace std;
int shu[4]={0};
struct poi{
    int a;
    int b;
    int c;
    int num;
    int name;
    int name2;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;

    while(t--){
        poi r[1000000];
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>r[i].a>>r[i].b>>r[i].c;
            int max1=0;
            max1=max(r[i].a,max(r[i].b,r[i].c));
            r[i].num=max1;
            ans=ans+max1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
