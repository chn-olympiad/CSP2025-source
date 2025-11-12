#include <bits/stdc++.h>
using namespace std;
string s[3010][5];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n+q;i++)cin>>s[i][1]>>s[i][2];
    for(int x=n+1;x<=n+q;x++){
        int len=s[x][1].size();
        int ans=0;
        for(int i=0;i<len;i++){
            for(int l=1;l+i-1<len;l++){
                string y1=s[x][1].substr(i,l);
                for(int k=1;k<=n;k++){
                    if(y1==s[k][1]){
                        string x1=s[x][1].substr(0,i),z1=s[x][1].substr(i+l,len-i-l+1);
                        string new1=x1+s[k][2]+z1;
                        if(new1==s[x][2])ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
