#include <bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    int cont;
    cin >> n;
    int ans;
    for(int i = 0;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i <= n;i++)
    {
        if(a[i] <= ans)
        {
            ans += a[i];
        }
    }
    ans = ans * 2;
    for(int i = 0;i <= n;i++)
    {
        if(a[i] <= ans)
        {
            ans += a[i];
        }
    }
    if(ans+=ans)
    {
        cont==1;
    else
    {
        cont==0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
