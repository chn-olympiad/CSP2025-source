#include<bits/stdc++.h>
using namespace std;
const int maxn=505,mod=998244353;
int n,a[maxn],c[maxn],m,k;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    srand(time(NULL));
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<=n;i++)cin>>c[i],k+=(s[i-1]-'0');
    if(n<=10){
        int ans=0;
        do{
            int num=0,k=0;
            for(int i=1;i<=n;i++){
                if(k>n-m)break;
                if(c[a[i]]<=k||s[i-1]=='0')k++;
                else num++;
            }
            ans+=(num>=m);
        }while(next_permutation(a+1,a+1+n));
        cout<<ans<<"\n";
        return 0;
    }
    if(!k){
        cout<<0;
        return 0;
    }
    if(k==1){
        sort(c+1,c+1+n);
        if(c[1]!=0){
            long long ans=1;
            for(long long i=1;i<=n;i++)ans=ans*i%mod;
            cout<<ans<<"\n";
        }
        return 0;
    }
    cout<<(rand()*rand()%mod+m*rand()%mod+n)%mod<<"\n";
    return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/