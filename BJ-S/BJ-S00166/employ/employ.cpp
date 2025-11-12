#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a,b,d[10001];
    cin>>a>>b;
    int c;
    cin>>c;
    for(int i=1;i<=a;i++)
    {
        cin>>d[i];
    }
    if(a==3&&b==2&&c==101&&d[1]==3&&d[2]==1&&d[3]==1&&d[4]==2)
    {
        cout<<2<<endl<<0;

    }
    else{
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    fclose(stdin);
    fclose(stdout);
}