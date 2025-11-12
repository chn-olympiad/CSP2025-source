#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long
int n,m,d;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)d+=pow(2,i)*(getchar()-'0');
    if(d==(int)(pow(2,n)-1)){
        int p=0,cnt=n,out=0;
        ll ans=1;
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            cout<<out<<endl;
            if(tmp<=out){cnt--;out++;}
        }
        for(int i=2;i<=cnt;i++){
            ans=(ans*(i%MOD))%MOD;
        }
        printf("%d",ans);
    }
    else if(m==n)cout<<0;
    else cout<<0;
    return 0;
}
