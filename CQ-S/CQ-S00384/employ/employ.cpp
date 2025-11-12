#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX=1e4+20,NAX=1e6+10,mod=998244353;
int n,m;
string str;
int a[MAX];
int p[MAX],bye,cnt;
ll ans=0;
bool check_all1(){
    for(int i=1;i<=n;i++){
        if(str[i]=='0'){return false;}
    }return true;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdin);
    scanf("%d%d",&n,&m);
    cin >> str;str=" "+str;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        p[i]=i;
    }
    if(check_all1()){
        for(int i=1;i<=n;i++){cnt+=(str[i]=='1');}
        ans=1;
        for(int i=1;i<=m;i++){
            (ans*=(cnt-i+1))%=mod;}
        for(int i=m+1;i<=cnt;i++){(ans*=2)%=mod;}
    }else{
        do{
            bye=0,cnt=0;
            for(int i=1;i<=n;i++){
                if(bye<a[p[i]] && str[i]!='0'){cnt++;}
                else{bye++;}
            }
            if(cnt>=m){ans++;}
        }while(next_permutation(p+1,p+1+n));
    }
    printf("%d",ans);
    return 0;
}