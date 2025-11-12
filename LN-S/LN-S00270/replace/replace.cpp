#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    string s[n+1][3];
    string t[q+1][3];
    string r[n+1];
    for(int i=1;i<=n;i++){
        scanf("%s%s",&s[i][1],&s[i][2]);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&t[i][1],&t[i][2]);
        r[i]=t[i][1];
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        int l1=s[i][1].size();
        int l2=t[i][1].size();
        for(int a=0;a<l2;a++){
            for(int b=a;b<a+l1;b++){
                if(r[i][a]==s[i][1][b-a])t[i][1][a]=s[i][2][b-a];
            }if(t[i][1]==t[i][2])ans++;
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
