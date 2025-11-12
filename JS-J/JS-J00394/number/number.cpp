#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    int k=0;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]>='0'&&n[i]<='9') {
           k++;
           a[k]=n[i]-'0';
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
    cout<<a[i];
    return 0;
}
