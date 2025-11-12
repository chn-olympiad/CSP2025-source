#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,e,f,s[500010];
bool s1[500010];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%lld",&s[i]);
    }
    for(int i=1;i<a;i++){
        for(int j=0;j<a;j++){
            if(s1[j]==1)continue;
            c=s[j],f=0;
            for(int x=j+1;x<j+i;x++){
                c=c^s[x];
                if(s1[x]==1){
                    j=x+1;
                    f=1;
                }
            }
            if(c==b&&f==0){
                d++;
                for(int x=j;x<j+i;x++){
                    s1[x]=1;
                }
            }
        }
    }
    printf("%lld",d);
    return 0;
}
