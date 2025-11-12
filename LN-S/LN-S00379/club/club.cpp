#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+5;
struct node{
    int a,b,c;
}arr[mxn];
int sum=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int q;
    cin>>q;
    for(int k=1;k<=q;k++){
        int n;
        cin>>n;
        long long sum;
        for(int i=1;i<=n;i++){
            cin>>arr[i].a>>arr[i].b>>arr[i].c;
            int mx=max(arr[i].a,arr[i].b);
            mx=max(mx,arr[i].c);
            cout<<mx;
        }

    }
    return 0;
}
