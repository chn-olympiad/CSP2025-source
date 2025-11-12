#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,sum=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j]>>b[j]>>c[j];
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        sort(c,c+n,cmp);
        for(int i=0;i<n/2;i++){
            sum+=a[i];
        }
        cout<<sum;
    }
    return 0;
}
