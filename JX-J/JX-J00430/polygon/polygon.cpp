#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long c[5005];
long long ans=0;
long long g=0;
int cn(int l,int r){
    int x=-25000000;
    for(int i=l;i<=r;i++){
        x = max(x,a[i]);
    }
    g = x;
    return 0;
}

int main(){
    //freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=c[i-1]+a[i];;
	}
	if(n==3){
        cn(1,3);
        if(c[3]>=g*2) cout<<1;
        else cout<<0;
	}
    else{
        for(int i=3;i<=n;i++){
        for(int l=1;l<=n-i+1;l++){
            int r = l+i-1;
            cn(l,r);
            if(c[r]-c[l-1]>g*2)
                ans++;
            }
        }
        cout<<ans;
    }

}
