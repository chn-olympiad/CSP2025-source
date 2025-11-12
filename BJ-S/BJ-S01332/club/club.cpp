#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],c[N];
long long f(int x,long long sum,int a2,int b2,int c2){
    if(a2>n/2||b2>n/2||c2>n/2)return -10000;
    if(x>n)return sum;
    long long a1=f(x+1,sum+a[x],a2+1,b2,c2);
    long long b1=f(x+1,sum+b[x],a2,b2+1,c2);
    long long c1=f(x+1,sum+c[x],a2,b2,c2+1);
    sum=max(a1,max(b1,c1));
    return sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        cout<<f(1,0,0,0,0)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
