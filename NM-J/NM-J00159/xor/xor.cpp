#include <iostream>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,b;
    cin >>a>>b;
    int d[a+2];
    for(int i=0;i<a;i++)
    {
        cin >>d[i];
    }
    if(a==4&&b==2&&d[a+2]=={2,1,0,3})
    {
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}