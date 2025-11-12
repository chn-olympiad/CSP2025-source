#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin)
    freopen("club.out","w",stdout)
long long t,n,a[10005]={0},b[10005]={0},c[10005]={0},I,M;
    cin>>t;
    for(int i=0;i<=t;i++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(c[i]>b[i]&&b[i]>a[i]&&c[i]>a[i]){
            I=c[i];
            }
            else if(b[i]>a[i]&&b[i]>c[i]){
            I=b[i];
            }
            else if(a[i]>b[i]&&a[i]>c[i]){
            I=a[i];
            }
            tmp=0 
            M=tmp+I;
        }
    }
    cout<<M;
return 0;
}
