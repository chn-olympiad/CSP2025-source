#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=505;

int main(){
    freopen("employ.in",read,iostream);
    freopen("employ.out",write,iostream);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool flag=false;
    int n,m,k;
    int s[MAXN];
    int c[MAXN];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0){
            flag=true;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(c[i]>c[j]){
                int temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }

        }

    }

    for(int i=1;i<=n;i++){
        if(c[i]>=i){
            k=i-1;
        }
    }
    if(flag==false){
       if(m>n-k){
           cout<<0;
           return 0;
       }
       LL ans=1;
       for(int i=n;i>0;i--){
           ans=(ans*i)%998244353;
       }
       cout<<ans;
       return 0;
    }


    return 0;
}
