#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={1,3,2,6,4,7,6,5,9};
    sort(a+1,a+9+1);
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
