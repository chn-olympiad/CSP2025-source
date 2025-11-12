#include<bits/stdc++.h>
namespace fzx{
    const int N=2e5+10,M=5e6+10;
    std::string s[N][3],t[N][3];
    int n,q;
    void special_1(){
        for(int i=1;i<=q;i++){
            if(t[i][1].size()!=t[i][2].size()){
                puts("0");
                continue;
            }
            int res=0;
            for(int j=1;j<=n;j++){
                int x=(int)t[i][1].find(s[j][1],0);
                while(x>=0){
                    std::string T=t[i][1].substr(0,x)+s[j][2]+t[i][1].substr(x+s[j][1].size(),t[i][1].size()-s[j][1].size()-x);
                    if(T==t[i][2])res++;
                    x=(int)t[i][1].find(s[j][1],x+1);
                }
            }
            printf("%d\n",res);
        }
    }
    void main(){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            std::cin>>s[i][1],
            std::cin>>s[i][2];
        for(int i=1;i<=q;i++)
            std::cin>>t[i][1],
            std::cin>>t[i][2];
        if((n<=1000&&s[1][1].size()<=2000)||q==1)//1,2,3,4,5,6,7,8,13,14
            special_1();
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    fzx::main();
    return 0;
}