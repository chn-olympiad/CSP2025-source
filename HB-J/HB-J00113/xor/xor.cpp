#include <iostream>
using namespace std;
int a[1000001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    int len = 1;
    int b = 1;
    int sum = 0;
    int c;
    while(len < n)
    {
        sum  = 0;
        for(int i = 0;i < b;i++)
        {
            c = a[i]^a[i+1];
            for(int j = i+2;j < len;j++)
            {
                c += c^a[i];
            }
            if(c == k)
            {
                sum++;
                return 0;
            }
        }
        len++;
    }
    printf("1");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
