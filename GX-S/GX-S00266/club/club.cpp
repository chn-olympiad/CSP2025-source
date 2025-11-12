#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,a,j,d1=0,d2=0,d3=0,ans=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int i=0;i<n;i++){
            int a[j];
            cin>>a[j];
            if(a[0]<a[1])
            {
                d2++;
            }else   d1++;
            if(a[1]>a[2])
            {
                d2++;
                ans+=a[1];
            }else d3++;
            if(a[0]>a[2])
            {
                d1++;
            }else d3++;
        }
    }
    cout<<d3<<endl;
    cout<<ans;
    return 0;
}
