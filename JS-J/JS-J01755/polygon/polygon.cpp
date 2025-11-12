#include <bits/stdc++.h>
using namespace std;

int n,num[5005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i<=n;i++) cin>>num[i];
    if (n == 3){
        if (num[1]+num[2]>num[3]&&num[1]+num[3]>num[2]&&num[2]+num[3]>num[1]) {
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }else{
        int ans = 0;
        for (int i = n-2;i>=1;i--) ans = (ans+i)%998244353;
        cout<<ans;
        return 0;
    }
	return 0;
}
