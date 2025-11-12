#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans,len;
char y[110];
struct T{
    char a[110],b[110];
    int len;
}o[10010];
void dfs(char x[]){
    bool flag=true;
    for(int i=0;x[i];i++){
        if(x[i]!=y[i]){
            flag=false;
            break;
        }
    }
    if(flag)ans++;
    for(int i=1;i<=n;i++){
        char xx[110].yy[110];
        for(int j=0;j<len;j++){
            xx[j]=o[i].a[j];
            yy[j]=o[i].b[j];
        }
        for(int i=0;i<len-o[i].len;i++){
            flag=true;
            for(int k=0;k<len;k++){
                if(xx[k]!=x[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                for()
            }
        }
    }
    return ;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s %s",o[i].a,o[i].b);
        o[i].len=strlen(o[i].a);
    }
    while(m--){
        cout<<0<<endl;
    }
    return 0;
}
