#include<cstdio>
using namespace std;
int a[10];char s[1000005];
void solve(){
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++) printf("%d",i);
    }
    printf("\n");
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int T=1;//scanf("%d",&T);
    while(T--) solve();
    return 0;
}
