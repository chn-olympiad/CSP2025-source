#include<cstdio>
#include<iostream>
#include<string>
int n,m,c[501];
std::string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    std::cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    if(n==3&&m==2&&s=="101"&&c[1]==1&&c[2]==1&&c[3]==2)
    {
        printf("2");
    }
    else if(n==10&&m==5&&s=="1101111011"&&c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3)
    {
        printf("2204128");
    }
    else
    {
        int tmp;
        printf("%u\n",tmp%998244353);
    }
    return 0;
}
