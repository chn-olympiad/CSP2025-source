#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
char str[1010][2010],str2[1010][2010],tmp[2010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>str[i]>>str2[i];
    }
    for(int i=0;i<m;i++){
        int res=0;
        string s,s2;
        cin>>s>>s2;
        int l=s.length();
        for(int j=1;j<=n;j++){
            int t=strlen(str[j]);
            for(int p=0;p<=l-t;p++){
                int flag=1;
                for(int k=p;k<p+t-1;k++){
                    if(str[j][k]!=s[k]){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    for(int k=0;k<l;k++) tmp[k]=s[k];
                    for(int k=p;k<p+t-1;k++){
                        tmp[k]=str2[j][p-k];
                    }
                    int flag2=1;
                    for(int i=0;i<l;i++){
                        if(tmp[i]!=s2[i]) {
                            flag2=0;
                            break;
                        }
                    }
                    if(flag2) res++;
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
//CCF!Please make the questions easier next year.thank you!
//qwq
