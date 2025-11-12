#include<bits/stdc++.h>
#define ftsydj 114514
using namespace std;
int tot;
struct cnm{
    int st,en,len;
}p[1919810];
void add(int x,int y){
    p[++tot].st=x;
    p[tot].en=y;
    p[tot].len=y-x+1;
}
int cmp(cnm x,cnm y){
    if(x.en!=y.en)return x.en<y.en;
    return x.st<y.st;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,i,j,x,ans=0,t=0,a[1919810];
    cin>>n>>k;
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=n;++i){
        x=0;
        for(j=i;j<=n;++j){
            x^=a[j];
            if(x==k)add(i,j);
        }
    }
    sort(p+1,p+tot+1,cmp);
    i=1;
    while(i<=tot){
        if(t<p[i].st)ans++,t=p[i].en;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}

/*
#######  #     #    ####   #    #          #     #   #####   #     #
#        #     #   #    #  #   #            #   #   ##   ##  #     #
#        #     #  #        #  #              # #    #     #  #     #
######   #     #  #        ###                #     #     #  #     #
#        #     #  #        #  #               #     #     #  #     #
#        #     #   #    #  #   #              #     ##   ##  #     #
#         #####     ####   #    #             #      #####    #####
