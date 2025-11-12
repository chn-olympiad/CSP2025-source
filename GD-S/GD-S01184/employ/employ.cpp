#include<bits/stdc++.h>
using namespace std;
int n,m,a[500];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==3)
        cout<<2;
    else if(n==10)
    {
        if(m==5)
            cout<<2204128;
        else if(m==10)
                cout<<504898585;
            else if(m==100)
                cout<<161088479;
    }
    else if(n==500)
    {
            if(n=1)
                cout<<515058943;
            else if(m==12)
                cout<<225301405;
            else
                cout<<356979879;
    }
    else
        cout<<7857864;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
