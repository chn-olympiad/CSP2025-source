#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int  m[10000];
    int  a,b,c,d;
    cin>>a>>b;
    c=a*b;

    for (int i=0;i<c;i++)
    {
        cin>>m[i];
        for (int j=0;j<c;j++)
        {


            if (m[i]<=m[i-1])
            {
                d=m[i-1];
                m[i-1]=m[i];
                m[i]=d;
            }
        }
    }
    d=a/b;


    cout<<d<<" "<<a;

//    sort(m,m+c);
 //   cout <<c;
    return 0;
}
