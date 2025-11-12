#include<bits/stdc++.h>
using namespace std;
int arr[1000001],op=0;
int main(void)
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    for(int i=0;i<=str.size()-1;i++)
    {
        if('0'<=str[i]&&str[i]<='9')
        {
            arr[++op]=str[i]-'0';
        }
    }
    sort(arr+1,arr+op+1);
    for(int i=op;i>=1;i--)
    {
        cout<<arr[i];
    }
    return 0;
}
