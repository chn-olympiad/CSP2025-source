#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    bool fl=1,ff=1;
    for(int i=1;i<=n;i++)
        if(s[i]=='0')
            fl=0;
        else
            ff=0;
    if(fl){
        printf("0\n");
        return 0;
    }
    if(m==n){
        if(ff==1){
            long long ans=1;
            for(int i=1;i<=n;i++)
                ans=ans*i%998244353;
            printf("ans\n");
        }
        else printf("0\n");
        return 0;
    }
    if(m==1){
        long long ans=1;
        for(int i=1;i<=n;i++)
        ans=ans*i%998244353;
        printf("ans\n");
    }
	return 0;
}
