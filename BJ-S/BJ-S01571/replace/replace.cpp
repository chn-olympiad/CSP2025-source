#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string s[200005][3],t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) cin >> s[i][1] >> s[i][2];
    while(q--){
        cin >> t1 >> t2;
        int m=t1.size(),m2=t2.size();
        if(m!=m2){
            printf("0\n");
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int len=s[i][1].size();
            for(int j=0;j+len-1<m;j++){
                int k=j+len-1;
                bool f=1;
                string nt1=t1;
                for(int l=j;l<=k;l++){
                    if(s[i][1][l-j]!=t1[l] || s[i][2][l-j]!=t2[l]){
                        f=0;
                        break;
                    }
                    nt1[l]=s[i][2][l-j];
                }
                if(f && nt1==t2) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
