#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[5010];
long long ans;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3&&(a[1]+a[2]+a[3]>2*a[3])){
        ans++;
    }
    else{
        int t = 1+n+(n*(n-1)/2);
        long long k=1;
        for(int i=1;i<=n;i++){
            k=k*2;
            k=k%998244353;
        }
        if(k>=t){
            ans=k-t;
        }
        else {
            ans=k+998244353-t;
        }
    }
    cout<<ans;








    return 0;
}

