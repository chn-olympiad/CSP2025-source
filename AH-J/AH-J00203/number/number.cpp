#include<bits/stdc++.h>
using namespace std;
string s;
long long k =0;
long long arr[1100000];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    cin >>s;
    for(int i =0;i<s.length();i++)
    {
        if(s[i] <='9' &&s[i] >='0')
        {
            arr[k] =s[i] -'0';
            k ++;
        }
    }
    sort(arr ,arr +k);
    
    for(int i =k-1;i >=0;i--)
    {
        cout <<arr[i];
    }
    
    return 0;
}
