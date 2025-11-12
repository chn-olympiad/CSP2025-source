#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("emplot.in","r",stdin);
    freopen("emplot.out","w",stdout);
    int a,b;
    cin>>a>>b;
    long long n;
    cin>>n;
    int h[1000000];
    for(int i=0;i<a;i++)cin>>h[i];
    int f[1000000];
    int l=0;
    while(n>0){
        int j=n%10;
        f[l]=j;
        l++;
        n/=10;
    }
    int q=0,sbdr=0;
    for(int i=0;i<a;i++){
        if(f[i]==1&&q<=b&&h[i]>=sbdr){
            q++;
        }else sbdr++;
    }
    cout<<998224353%q;
    return 0;
}
