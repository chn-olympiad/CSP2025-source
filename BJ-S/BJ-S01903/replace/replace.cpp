#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        string tt=t1[i];
        int ans=0;
        int len=t1[i].size();
        for(int j=1;j<=n;j++){
            int x,y;
            int len2=s1[j].size();
            bool f=false;
            for(int k=0;k<len;k++){
                bool fff=true;
                for(int kk=k;kk<k+len2;kk++){
                    if(t1[i][kk]!=s1[j][kk-k]){
                        fff=false;
                        break;
                    }
                }
                if(fff){
                    f=fff;
                    x=k,y=k+len2-1;
                }
            }
            if(f){
                int xxx=0;
                for(int k=x;k<=y;k++){
                    t1[i][k]=s2[j][xxx++];
                }
                bool ff=true;
                for(int k=0;k<len;k++){
                    if(t1[i][k]!=t2[i][k]){
                        ff=false;
                        break;
                    }
                }
                if(ff){
                    ans++;
                }
            }
            t1[i]=tt;
        }
        printf("%d\n",ans);
    }
    return 0;
}
