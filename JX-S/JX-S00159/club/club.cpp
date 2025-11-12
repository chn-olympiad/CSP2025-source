#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010],ans,vis[100010],r[5],ma,n,t,flag;
bool cmp(int aaa,int bbb){
    return aaa>bbb;
}
namespace n_2{
    int aaa,bbb,ccc,ddd,eee,fff,ggg;
    int main(){
        for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]==0&&c[i]==0)  flag=1;
        else flag=0;
    }
        if(flag==1) sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[i];
        }
    cout<<ans;
    return 0;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;

    while(t--){
        cin>>n;
        n_2::main();

    }
    return 0;
}

