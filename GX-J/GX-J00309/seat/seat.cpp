#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[110];
int a1;
int x(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>arr[i];
    }
    a1=arr[0];
    sort(arr+0,arr+n*m,x);
    for(int i=0;i<n*m;i++)
    {
        if(arr[i]==a1)
        {
            a1=i+1;
        }
    }
    int lie=a1/n;
    int yu=a1%n;
    if(lie==0)
    {
        cout<<1<<' '<<yu;
        return 0;
    }
    else if(yu==0)
    {
        if(lie%2==0)
        {
            cout<<lie<<' '<<1;
        }
        else
        {
            cout<<lie<<' '<<n;
        }
    }
    else
    {
        if(lie%2!=0)
        {
            cout<<lie+1<<' '<<n-yu+1;
        }
        else
        {
            cout<<lie+1<<' '<<yu;
        }
    }
    return 0;
}
