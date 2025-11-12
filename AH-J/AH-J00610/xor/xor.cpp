#include <bits/stdc++.h>
using namespace std;
int n,k,a[50005],sum[50005],cnt,cnt0,ans;
bool flag[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }//特殊性质A:对于所有 1 ≤ i ≤ n,均有 ai = 1。
    for(int i=1; i<=n; i++){
        if(a[i]==1) cnt++;
        if(a[i]==0) cnt0++;//用于特殊性质B
    }if(cnt==n){
        if(k==1) cout << n;
        else if(k==0) cout << n/2;
        else cout << 0;
        return 0;
    }//特殊性质 B:对于所有 1 ≤ i ≤ n,均有 0 ≤ a i ≤ 1。
    if(cnt+cnt0==n){
        if(k==1) cout << cnt;
        else if(k==0) cout << cnt0;
        else cout << 0;
        return 0;
    }
    //qita
    for(int i=1; i<=n; i++){
        if(a[i]==k) ans++;
    }cout << ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

