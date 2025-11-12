#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int arr[1000001],n=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if( s[i]-'0'<=9 && s[i]-'0'>=0 )
        {
            arr[n]=s[i]-'0';
            n++;
        }
    }
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i];
    }
    return 0;
}
