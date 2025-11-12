#include<cstdio>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k
    scanf("%d%d",&n,&k);
    int a[n],b[n+2]={};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[0]=a[0];
    int h=0;
    for(int i=1;i<n;i++)
    {
        if(b[i-1]==k)
        {
            h++;
            b[i]==a[i];
        }
        else
        {
            b[i]=a[i]^b[i-1];
        }
    }            
    printf("%d",h);    
    fclose(stdin);
    fclose(stdout);
    return 0;
 }   
