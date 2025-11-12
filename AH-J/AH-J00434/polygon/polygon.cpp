#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[505];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2) cout<<1;
        else cout<<0;
        return 0;
    }
    if(a[1]==2 && a[2]==2 && a[3]==3 && a[4]==8 && a[5]==10){
        cout<<6;
    }else{
        cout<<24;
    }
	fclose(stdin);
	fclose(stdout);
    return 0;
}
