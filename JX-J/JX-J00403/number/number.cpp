#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    const string num="0123456789";
    string a;
    cin>>a;
    //for(int i=0;i<strlen(a);i++)
    //{
    //    for(int j=9;j>=0;j--)
    //    {
    //        if(a[i]==num[j])
    //        {
    //            cout<<num[j];
    //            break;
    //        }
    //    }
    //}
    cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
