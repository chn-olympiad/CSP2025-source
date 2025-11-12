#include<bits/stdc++.h>
using namespace std;

const int maxn=1e3+10;
char s[maxn];
int arr[maxn],pos[maxn];
int n,m;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        pos[i]=i;
    }

    int ans=0;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0') cnt++;
            else if(arr[pos[i]]<=cnt) cnt++;
        }
        if(n-cnt>=m) ans++;
    //    fprintf(stderr,"%d\n",cnt);
    }while(next_permutation(pos+1,pos+1+n));
    printf("%d\n",ans);
}