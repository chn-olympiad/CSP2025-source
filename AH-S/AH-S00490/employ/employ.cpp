#include<bits/stdc++.h>
using namespace std;const long long mod=998244353;int ch[10010];
int n,m,c[510],a[15],b[15];string str;vector<pair<int,int> >vc;long long ans=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>str;for(int i=1;i<=n;i++)ch[i]=str[i-1]-'0';
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=100){
        for(int i=1;i<=n;i++)a[i]=i;
        for(int i=1;i<=n;i++)b[i]=1;
        do{
            int r=0,nu=0;
            for(int i=1;i<=n;i++){
                if(ch[i]==1&&nu<c[a[i]])++r;
                else ++nu;
                //cout<<'1'<<a[i]<<' ';
            }
            //cout<<r<<'\n';
            if(r>=m)++ans;

        }while(next_permutation(a+1,a+n+1));
        cout<<ans;
    }
    return 0;
}
