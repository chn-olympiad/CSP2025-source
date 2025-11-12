//#include <iostream>
#include<bits/stdc++.h>
#include<fstream>
char a[1000000]={'A'};
int b[1000000]/*={0}*/;
//#include<cstdio>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //well,guys,i lost!for the"number"!
    int i=0,ii=0,z,bk,j=0;
    cin>>a;
    while(a[i]!='A')
    {
        if('0'<=a[i]<='9') b[j]=a[i]-48;j++;
        i++;
    }
    j--;
    i--;
    while(ii<=i);
    {
        if(b[ii]<b[ii+1])
        {
            bk=ii+1;
            while(bk!=0&&b[bk]>b[bk-1])
            {
                z=b[bk];
                b[bk]=b[bk-1];
                b[bk-1]=z;
                bk--;
            }
        }
        ii++;
    }
    i=0;
    while(i<=j)
    {
        cout<<b[i];
        i++;
    }
    /*fclose("number.in");
    fclose("number.out");*/
    return 0;
}
