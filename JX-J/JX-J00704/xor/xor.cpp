#include <bits/stdc++.h>
using namespace std;
int a[500010],asn[2010][2010];
long long k, ans,s[20];
int xoor(int a,int b){
    int c=0,sum=0;
    if(b>a) swap(a,b);
    while(a){
        if(b){ if((a%2)!=(b%2)){ c+=s[sum]; } b/=2; }
        else{ c+=s[sum]*(a%2); }
        sum++; a/=2;
    }
    return c;
}
int n;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    s[0]=1;
    for(int i=1;i<=19;i++){ s[i]=s[i-1]*2; }
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i] == k) ans++;
        asn[i][i] = a[i];
    }
    if(k == 0) {
        ans = 1;
    } else {
        for(int i=1;i<=n;i++){
            for(int j=2;j+i-1<=n;j++){
                asn[j][i]=xoor(asn[j][j-i],a[j-i+1]);
                if(asn[j][i]==k) ans++;
            }
        }
    }
    cout<<ans;
	return 0;
}
