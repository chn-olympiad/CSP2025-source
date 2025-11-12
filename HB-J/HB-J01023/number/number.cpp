#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;
char IN[2000000] ;
int bucket[19] ;
int digit(char c)
{
    return c >= '0' && c <= '9' ;
}
int main()
{
    freopen("number.in", "r", stdin) ;
    freopen("number.out", "w", stdout) ;
    cin>>IN ;
    int len = strlen(IN) ;
    for(int i=0;i<len;i++)
    {
        char now = IN[i] ;
        if(now >= '0' && now <= '9')
        {
            bucket[now - '0'] += 1 ;
        }
    }
    for(int i=9;i>=0;--i)
    {
        for(int j=1;j<=bucket[i];++j)
        {
            cout << i ;
        }
    }
    cout << '\n' ;
}
