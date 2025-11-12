#include<bits/stdc++.h>
#define mod 998244353
#define N 502
using namespace std;
int n,m;
int s[N];
int c[N];
int cnt[N];
int p[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%1d",s+i);
    for(int i=1;i<=n;i++){
        scanf("%d",c+i);
        cnt[c[i]]++;
        p[i]=i;
    }
    int res=0;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            int cur=p[i];
            if(i-cnt-1>=c[cur])continue;
            if(s[i]){
                cnt++;
            }
        }
        if(cnt>=m)res++;
    }while(next_permutation(p+1,p+n+1));
    printf("%d\n",res);
}