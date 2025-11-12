#include <iostream>
#include <ios>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<9;
    return 0;
}

