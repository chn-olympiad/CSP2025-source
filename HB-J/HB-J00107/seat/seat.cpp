#include <bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    cin>>n>>m;
    int p=m*n,qwert[p+1];
    for (int i=1;i<=p;i++)
        cin>>qwert[i];
    int num=qwert[1];
    sort (qwert+1,qwert+p+1,cmp);
    int l=1,r=p,mid;
    while (true)
    {
        mid=(l+r)/2;
        if (qwert[mid]<num) r=mid-1;
        else if (qwert[mid]>num) l=mid+1;
        else break;
    }
    int lie=(mid+n-1)/n,hang,fuzhu=mid%n;
    if (lie%2) hang=(fuzhu?fuzhu:n);
    else hang=(fuzhu?n-fuzhu+1:1);
    cout<<lie<<' '<<hang;
    return 0;
}
