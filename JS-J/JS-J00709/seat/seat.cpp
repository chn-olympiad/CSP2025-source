#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r=1,l,a;
    cin >> n >> m;
    vector<int> s(n*m);
    for(int i = 1;i < n*m;i++)
    {
        cin >> s[i];
    }
    l = s[1];
    for(int i = 1;i<n*m;i++)
    {
        for(int j = 1;j<=n*m-i-1;j++)
        {
            if(s[j] < s[j+1])
            {
                swap(s[j],s[j+1]);
            }
        }
    }
    for(int i = 1;i <= n*m;i++)
    {
        if(s[i]==l)
        {
            r = i;
        }
    }
    int b = ceil(r*1.0/n);
    if(b%2==1)
    {
        if(r%n==0)
        {
            a = n;
        }
        else
        {
            a = r%n;
        }
    }
    else
    {
        if(r%n==0){
            a = 1;
        }
        else{
            a = n-r%n+1;
        }
    }
    cout << b << ' ' << a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
