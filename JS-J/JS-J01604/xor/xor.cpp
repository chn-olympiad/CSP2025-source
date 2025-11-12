#include <bits/stdc++.h>
using namespace std;

int a,b[500010],c,k;
int yihuo(int a,int b)
{
    return (~(a&b))&(a|b);
}

int getK(int l1)
{
    if (b[l1]==k)
    {
        return l1;
    }
    int l=yihuo(b[l1],b[l1+1])
    if (l==k)
    {
        return l1+1;
    }
    for(int i=l1;i<a;i++)
    {
        l=yihuo(b[i],l);
        if(l==k)
            return i;
    }
    return -1;
}
void getA(int* A,int lest,int deep)
{
    for(int i=lest;i<a;i++)
    {
        A[deep]=b[i];
        int get =getK(i);
        if(get==-1)
        {
            if(deep>c)
                c=deep;
        }
        else getA(A,get+1,deep+1);
    }
}


int main()
{

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>a>>k;
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    int A[500000];
    getA(A,0,0)
    cout<<c;
}
