#include<bits/stdc++.h>
using namespace std;
char iner;
int numbers[11];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    iner=getchar();
    while(iner!='\n'){
        if(iner>='0'&&iner<='9')
            numbers[iner-'0']++;
        iner=getchar();
    }
    for(int i=9;i>=0;i--)
        while(numbers[i]--)
            printf("%d",i);
    return 0;
}

