#include<bits/stdc++.h>
using namespace std;
int j;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int m[100005];
    for(int i = 0;i <= a.length()-1;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            m[j]=a[i]-'0';
            j++;
        }
    }
    sort(m,m+j);
    for(int i = j-1;i >= 0;i--)
    {
        cout << m[i];
    }
    return 0;
}
