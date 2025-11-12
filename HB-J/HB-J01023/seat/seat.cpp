#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int maze[80][80] ;
vector<int> V ;
bool cmp(int a,int b)
{
    return a > b ;
}
int CEIL(int a,int b)
{
    if(a % b) return a/b+1;
    return a/b ;
}
int main()
{
    freopen("seat.in", "r", stdin) ;
    freopen("seat.out", "w", stdout);
    int n ,m;
    cin>>n>>m ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>maze[i][j] ;
            V.push_back(maze[i][j]) ;
        }
    }
    int R = maze[1][1] ;
    sort(V.begin(), V.end(), cmp) ;
    int K ;
    for(int i=0;i<V.size();++i)
    {
        if(V[i] == R)
        {
            K = i+1 ;
            break ;
        }
    }
    int M = CEIL(K, n), N ;
    if(M % 2 == 0)
    {
        if(K % n == 0)
        {
            N = 1 ;
        }
        else
        {
            N = n-(K % n)+1 ;
        }
    }
    else
    {
        if(K % n == 0)
        {
            N = n ;
        }
        else
        {
            N = K % n ;
        }
    }
    cout << M << ' ' << N ;
}
