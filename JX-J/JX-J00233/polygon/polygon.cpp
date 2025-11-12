#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    if(n<3) cout<<0;
    else if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    else{
        if(a[n]==1) cout<<0;
    }
    return 0;
}
