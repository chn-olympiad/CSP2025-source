#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a;
int n[N],len;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int l=a.size()-1;
    for(int i=0;i<=l;i++)
    {
        if('0'<=a[i]&&a[i]<='9')
        {
            len++;
            n[len]=a[i]-'0';
        }
    }
    sort(n+1,n+1+len);
	for(int i=len;i>=1;i--)
        cout<<n[i];
    return 0;
}
