#include<bits/stdc++.h>
using namespace std;
int asum,bsum,csum,ans;
int amax,bmax,cmax;
int a[20010],b[20010],c[20010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int j=1;j <= t;j++){
		int n;
        cin >> n;
        for(int i=1;i <= n;i++){
            cin >> a[i] >> b[i] >> c[i];
            amax = max(a[i],amax);
            bmax = max(b[i],bmax);
            cmax = max(c[i],cmax);
        }
        for(int i=1;i <= n;i++){
			if(a[i] == amax && asum <= n / 2 && max(a[i],max(b[i],c[i])) == a[i]){
				asum++;
				ans += a[i];
				a[i] = 0;
			}if(b[i] == bmax && bsum <= n / 2 && max(a[i],max(b[i],c[i])) == b[i]){
				bsum++;
				ans += b[i];
				b[i] = 0;
			}if(c[i] == cmax && csum <= n / 2 && max(a[i],max(b[i],c[i])) == c[i]){
				csum++;
				ans += c[i];
				c[i] = 0;
			}
		}
		cout << ans << endl;
		ans = 0;
		amax = 0;
		bmax = 0;
		cmax = 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
