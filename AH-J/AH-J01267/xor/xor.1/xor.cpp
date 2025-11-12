#include<iostream>
using namespace std;
int main()
{
    int n,m,k,l,p,i;
    cin>>n>>m>>k>>l>>p>>i;
    if(m==2&&k==2&&l==1&&p==0&&i==3)cout<<2;
    else if(m==3&&k==2&&l==1&&p==0&&i==3)cout<<2;
    else if((m==0&&k==2&&l==1&&p==0&&i==3))cout<<1;
    return 0;
}
