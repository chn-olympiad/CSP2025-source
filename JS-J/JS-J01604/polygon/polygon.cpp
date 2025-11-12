#include <bits/stdc++.h>
using namespace std;

int a,b[2050],c=0;
//map<int,int> times;
bool Istrue(int* A,int len)
{
    int he=0,mx=0;
    for(int i=0;i<len;i++)
    {
        he+=A[i];
        if(A[i]>mx)
        {
            mx=A[i];
        }
    }
    bool re=he>(2*mx);
    return re;
}
void getA(int* A,int lest,int deep)
{

    if(deep>=3)
    {
        if(Istrue(A,deep))
        {
            c++;
            if(c==998244353)
            {
                c=0;
            }
            /*for(int i=0;i<deep;i++)
            {
                cout<<A[i]<<endl;
            }*/
        }
    }
    for(int i=lest;i<a;i++)
    {
        A[deep]=b[i];
        getA(A,i+1,deep+1);
    }
}


int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++)
    {
        int in;
        cin>>b[i];
    }
    int x[5020]={0};
    getA(x,0,0);
    cout<<c;
}
