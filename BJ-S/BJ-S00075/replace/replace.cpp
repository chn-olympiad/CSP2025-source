#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
string a[N],b[N],s,t;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    while(q--){
        int ans=0;
        cin>>s>>t;
        //cout<<s<<" "<<s.size()<<" "<<t<<" "<<t.size();
        if(s.size()!=t.size()){
            printf("0\n");
            continue;
        }
        int be,e;
        for(be=0;be<s.size();be++){
            for(e=be+1;e<s.size();e++){
                for(int i=1,j;i<=n;i++){
                    if(e-be+1!=a[i].size()) continue;
                    //printf("#      #    #%d %d %d\n\n",i,be,e);
                    for(j=0;j<s.size();j++) {
                            if(be<=j && j<=e) {
                                    if(a[i][j-be]!=s[j] || b[i][j-be]!=t[j])
                                    break;
                            }
                            else if(s[j]!=t[j]) break;
                            //printf("%d %c %c\n",j,s[j],t[j]);
                    }
                    if(j==s.size()){
                        //printf("\n%d %d %d ",i,be,e);
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
