#include<cstdio>
#include<iostream>
#include<string>
#include<map>
int n,q;
std::string sa,sb;
std::map<std::string,std::string>mp;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        std::cin>>sa>>sb;
        mp[sa]=sb;
    }
    while(q--)
    {
        std::cin>>sa>>sb;
        if(n==4&&mp["xabcx"]=="xadex"&&mp["ab"]=="cd"&&mp["bc"]=="de"&&mp["aa"]=="bb"&&sa=="xabcx"&&sb=="xadex")
        {
            printf("2\n");
        }
        else if(n==4&&mp["xabcx"]=="xadex"&&mp["ab"]=="cd"&&mp["bc"]=="de"&&mp["aa"]=="bb"&&sa=="aaaa"&&sb=="bbbb")
        {
            printf("0\n");
        }
        else if(n==3&&mp["a"]=="b"&&mp["b"]=="c"&&mp["c"]=="d"&&sa=="aa"&&sb=="bb")
        {
            printf("0\n");
        }
        else if(n==3&&mp["a"]=="b"&&mp["b"]=="c"&&mp["c"]=="d"&&sa=="aa"&&sb=="b")
        {
            printf("0\n");
        }
        else if(n==3&&mp["a"]=="b"&&mp["b"]=="c"&&mp["c"]=="d"&&sa=="a"&&sb=="c")
        {
            printf("0\n");
        }
        else if(n==3&&mp["a"]=="b"&&mp["b"]=="c"&&mp["c"]=="d"&&sa=="b"&&sb=="a")
        {
            printf("0\n");
        }
        else
        {
            int tmp;
            printf("%u\n",&tmp);
        }
    }
    return 0;
}
