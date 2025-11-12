#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
int n, a[5005], maxa, s[5005];
void ts(){
	ll fz=n*(n-1), fm=2, ans=0; 
	for (int i=3; i<=n; i++){
		fz=(fz*(1ll)*(n-i+1))%mod;
		fm=(fm*(1ll)*i)%mod;
		//cout << fz << ' ' << fm << '\n';
		ans=(ans+(fz/fm))%mod;
	}
	printf("%lld", ans);
	return;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    int tmp=0;
    for (int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if (a[i]>maxa) maxa=a[i];
        if (a[i]>1) tmp=1;
    }
    if (!tmp){
		ts();
		return 0;
	}
    sort(a+1, a+n+1);
    if (n==1 || n==2){
        printf("0");
        return 0;
    }else if (n==3){
        if (a[1]+a[2]>a[3]) printf("1");
        else printf("0");
        return 0;
    }
    for (int i=1; i<=n; i++){
        s[i]=s[i-1]+a[i];
    }
    return 0;
}
