#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rds(){
    char c=getchar();
    string s="";
    while (c<'a' or c>'z') c=getchar();
    while (c>='a' and c<='z') s+=c,c=getchar();
    return s;
}
string a[200100][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        a[i][0]=rds(),a[i][1]=rds();
    }
    for (int i=1;i<=m;i++){
        string ss,t;
        ss=rds(); t=rds();
        int ans=0;
        for (int j=1;j<=n;j++){
            string s=ss;
            //cerr << s << " " << a[j][0] << "\n";
            for (int k=0;k+a[j][0].size()-1<s.size();k++){
                for (int l=0;l<a[j][0].size();l++){
                    //cerr << j << " " << k << " " << l << s[k+l] << " " << a[j][0][l] << "\n";
                    if (s[k+l]!=a[j][0][l]){
                        break;
                    }
                    else s[k+l]=a[j][1][l];
                }
                if (s == t) ans++;
                s = ss;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
