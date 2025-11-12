#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
    }
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b=a.size(),c[b]={11},d=0,z=0;
    for(int i=0;i<b;i++)
    {
        if(a[i]-'0'==0||a[i]-'0'==1||a[i]-'0'==2||a[i]-'0'==3||a[i]-'0'==4||a[i]-'0'==5||a[i]-'0'==6||a[i]-'0'==7||a[i]-'0'==8||a[i]-'0'==9)
        {
            c[i]=a[i]-'0';
            z=z+1;
        }
    }
    sort(c,c+b,cmp);
    d=d+c[z-1];
    for(int i=0;i<z-1;i++)
    {
        d=d+c[i]*pow(10,z-i-1);
        //cout<<i<<" "<<d<<endl;
    }
    cout<<d;
    return 0;
}
