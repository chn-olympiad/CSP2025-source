#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string s1[N],s2[N];
int slen[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        slen[i]=s1[i].length();
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int tlen=t1.length();
        if(tlen!=t2.length()){
            printf("0\n");
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j+slen[i]-1<tlen;j++){
                if(t1[j]==s1[i][0]){
                    bool flag=true;
                    for(int k=0;k<j;k++){
                        if(t1[k]!=t2[k]){
                            flag=false;
                            break;
                        }

                    }
                    for(int k=0;k<slen[i];k++){
                        if(s1[i][k]!=t1[j+k]||s2[i][k]!=t2[j+k]){
                            flag=false;
                            break;
                        }
                    }
                    for(int k=j+slen[i];k<tlen;k++){
                        if(t1[k]!=t2[k]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
