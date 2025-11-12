#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    int n,m,c,r,k;
    cin>>n>>m;
    int p=n*m;
    for(int i=0;i<p;i++)
        cin>>a[i];
    for(int i=1;i<p;i++)
    {
        if(a[i]>a[0]) k++;

    }
    k+=1;
    if(k>n){
        c=k/n+1;
        r=k%n;
        cout<<c<<" "<<r+1;
    }
    if(k<n){
        cout<<"1"<<" "<<k;
    }
    if(k==n){
        cout<<"1"<<" "<<k;
    }
    return 0;
}

