#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxn,zong,ans=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i =3;i<=n;i++){
        for(int j=n;j>=i;j--){maxn=a[j]*2;zong=0;for(int c=j;c>=j-i;c--){zong+=a[c];}
            if(zong>maxn){ans++;}
    }
    }
    cout<<ans*3;return 0;
}
