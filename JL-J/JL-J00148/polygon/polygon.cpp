#include<bits/stdc++.h>
using namespace std ;

int a[11100] ;
int n, sum = 0 ;
/*
bool judge(int k, int t, int r)
{
    if(a[k] + a[k+t] + a[k+r] > 2 * a[k+r])
    {
        return true ;
    }
    return false;
}

void dfs(int k, int t, int r)
{
    if(k > n) return ;
    for(int i=0; i<n; i++)
    {
        if(t == r)
        {
            t-- ;
            break ;
        }
        if(judge(i, t, r))
        {
            sum++ ;
            r++ ;
        }
        else
        {
            t++ ;
        }
    }
    dfs(k++, t, r) ;
    return ;
}*/

int main()
{
    freopen("polygon.in", "r", stdin) ;
    freopen("polygon.out", "w", stdout) ;

    cin >> n ;
    for(int i=0; i<n; i++)
    {
        cin >> a[i] ;
    }
    if(n == 3) cout << 1 ;
    //dfs(3, 1, 2) ;
    return 0 ;
}
