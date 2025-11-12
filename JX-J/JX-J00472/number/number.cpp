#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    string b="";
    int j=0,d=0;
    cin>>a;
    for (int i=0;i<=a.length();i++)
    {
        if (a[i]>'0'&&a[i]<'9')
        {
            b+=a[i];
            j++;
        }

    }
    for (int i=1;i<=1001;i++)
    {
        for (int k=1;k<=j-1;k++)
        {
            if (b[k]>b[k-1])
            {
                swap(b[k],b[k-1]);

            }
        }
    }
    d=stoi(b);
    cout<<d;
    return 0;

}
