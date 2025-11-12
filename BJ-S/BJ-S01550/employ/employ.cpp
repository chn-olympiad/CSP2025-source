#include <bits/stdc++.h>
using namespace std;
int a[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int sum=0,n2=n;
    for(int i=0;i<n2;i++){
        cin>>a[i];
        if(a[i]==0){
            sum++;
            n--;
        }
    }
    long long l=n,k=1,r=k;
    for(int i=1;i<=m-1;i++){
        n--;
        l*=n;
        k++;
        r*=k;
        if(l%r==0){
            l/=r;
            r=1;
        }
    }
    cout<<(l+sum)%998244353;
    return 0;
}
