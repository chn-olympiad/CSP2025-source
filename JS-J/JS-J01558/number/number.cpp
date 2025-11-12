#include<bits/stdc++.h>
using namespace std;
string n;
int arr[1000005];
int x=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]>='0'&&n[i]<='9')
            arr[x++]=n[i]-'0';
    }
    sort(arr,arr+x);
    for(int i=x-1;i>=0;i--)
        cout<<arr[i];
    return 0;
}
