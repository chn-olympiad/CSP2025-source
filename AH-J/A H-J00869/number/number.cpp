#include<string>
#include<iostream>
using namespace std;         
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    long long b[10]={};
    for(;;)
    {
        scanf("%c",&a);
        if(!(a<='9'&&a>='0'||a<='z'&&a>='a'))
        {
            break;
        }    
        if(a<='9'&&a>='0')
        {
            b[a-'0']++;
        }
    }      
    bool p=1;
    for(int i=9;i>0;i--)
    {
        p=0;
        while(b[i]-->0)
        {
            printf("%d",i);
        }    
    }
    if(p)
    {
        printf("0");
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    while(b[0]-->0)
    {
        printf("0");
    }        
    fclose(stdin);
    fclose(stdout);
    return 0;
}        
