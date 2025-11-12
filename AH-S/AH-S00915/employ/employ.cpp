#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 998244353
using namespace std;
int n,m,c[1000],s[1000];
string ss;
long long ans;
int a[1000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>ss;
    for(int i=0;i<n;i++){
        s[i+1]=ss[i]-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        a[i]=i;
    }
    do{
        int cnt=0,t=0;
        for(int i=1;i<=n;i++){
            if(t>=c[a[i]]||s[i]==0){
                t++;
            }else cnt++;
        }
        if(cnt>=m) ans=(ans+1)%MOD;
    }while(next_permutation(a+1,a+1+n));
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
