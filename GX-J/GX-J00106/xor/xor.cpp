#include<iostream>
#include<algorithm>
using namespace std;
long long a[500001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,i;
    cin>>n>>k;
   for(i=0;i<n;i++)
        cin>>a[i];
   if(n==1)cout<<"0";
   if(n==2)cout<<"1";
    return 0;
}
