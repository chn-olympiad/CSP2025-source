#include<bits/stdc++.h>using namespace std;

int main(){
    freopen ("number.in","w",number.in);
    freopen("number.out","r".number.out);
    int n,k,a[10000],v=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        v=a[i]+v;
    }
    cout<<v/2;
    

}

