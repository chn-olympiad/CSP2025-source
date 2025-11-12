#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    int a[n];
    for(int i=0;i<n;i++{
        cin<<a[n];
    }
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                a[j]+=a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]-=a[j+1];
            }
        }
    }
    int ans=1;
    for(int i=1;i<a[n-1];i++){
        ans*=i;
    }
    cout<<ans;
}
