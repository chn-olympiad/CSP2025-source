#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;int l,r;
int a[maxn],f[maxn];int df=0;
long long s=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=a[1],b=a[2],c=a[3];
    if(max(x,max(b,c))*2>=x+b+c){
        cout<<"0"<<endl;
        return 0;
    }
    cout<<"1"<<endl;
    return 0;
}
