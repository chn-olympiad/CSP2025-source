#include <bits/stdc++.h>
using namespace std;

int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int sum=s.size();
    int k=1;
    for(int i=0;i<sum;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a+1,a+k);
    for(int i=k-1;i>=1;i--)
    {
        cout << a[i];
    }
    return 0;
}
