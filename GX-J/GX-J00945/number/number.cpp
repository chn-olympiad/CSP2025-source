#include<bits/stdc++.h>
using namespace std;
int arr[1000009]={0};
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            arr[a]=s[i]-'0';
            a++;
        }
    }
    sort(arr+1,arr+a,cmp);
    for(int i=1;i<a;i++)
        cout<<arr[i];
    return 0;
}
