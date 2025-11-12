#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
string s[200010][3],t[200010][3];
void DFS_(string x,string y,int s){
    if(x==y){
        ans++;
        return;
    }
    if(s>10000)return;
    for(int i=0;i<x.length();i++)for(int j=1;j<=n;j++){
        if(i+s[(int)j][1].length()-1<x.length()){
            bool kg=0;
            for(int k=i;k<=i+s[(int)j][1].length()-1;k++)if(x[k]!=s[(int)j][1][k-i+1])kg=1,break;
            if(kg)continue;
            for(int k=i;k<=i+s[(int)j][1].length()-1;k++)x[k]=s[(int)j][2][k-i+1];
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)cin>>s[(int)i][1]>>s[(int)i][2];
    for(int i=1;i<=q;i++){
        cin>>t[(int)i][1]>>t[(int)i][2];
        DFS_(t[(int)i][1],t[(int)i][2]);
        printf("%d\n",ans);
    }
    return 0;
}
