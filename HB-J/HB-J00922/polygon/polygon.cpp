#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b=0,max=0,num=0;
    long long asdf=1;
    for(int i=1;i<=n;i++){
        asdf*=i;
    }
    for(long long i=0;i<asdf;i++){
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;i++){
                b+=a[j];
                max=max(max,a[j]);
            }
            if(b>max*2)num++;
        }
        a.push_back();
    }
}
