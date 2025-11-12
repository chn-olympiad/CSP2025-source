#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    long long lg=1;

    for(long long i =0;i<n.size();i++)
    {
        if(n[i]<='9'&&n[i]>='0')
        {
            a [i] = n[i]-'0';

            lg++;
        }


    }

    sort(a,a+lg);
    while(lg>0)
    {


        cout<<a[lg];
        lg--;

    }
}
