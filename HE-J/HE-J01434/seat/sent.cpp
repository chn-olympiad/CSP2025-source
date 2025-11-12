#include<iostream>
using namespace std;
int main()
{
    int n,m,a[100],h;
    cin>>n>>m>>a[100];
    for(int i=0;i<=n*m;i++)
    {
        if(a[i]<a[i+1])
        {
            h=a[i]; 
            a[i]=a[i+1];
            a[i+1]=h;
        }
        cout<<h<<" ";
    }
    return 0£»
}
