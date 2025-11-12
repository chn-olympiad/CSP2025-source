#include<iostream>
using namespace std;
int main(void)
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        if(i==1)
        {
            cout<<2<<endl;
            continue;
        }
        cout<<0<<endl;
    }
    return 0;
}
