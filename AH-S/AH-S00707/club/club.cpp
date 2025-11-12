#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        bool flag1=0;
        cin>>n;
        node f[n+5];
        int maxn[n+5]={};
        for(int i=1;i<=n;i++){
            cin>>f[i].a>>f[i].b>>f[i].c;
            if(f[i].b!=0||f[i].c!=0) flag1=1;
            maxn[i]=max(f[i].a,f[i].b);
            maxn[i]=max(maxn[i],f[i].c);
        }
        if(flag1==0){
            sort(maxn+1,maxn+n+1);
            for(int i=n;i>=n/2;i--){
                sum+=maxn[i];
            }
            cout<<sum<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                sum+=maxn[i];
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
