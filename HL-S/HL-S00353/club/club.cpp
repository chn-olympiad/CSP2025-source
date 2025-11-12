#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int a[100010],b[100010],c[100010];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
    	cin >> n;
    	int ans = 0;
    	if(n==2){
    		int a,b,c,d,e,f;
    		cin >> a >> b >> c >> d >> e >> f;
    		ans = max(a+e,a+f);
    		ans = max(ans,max(b+d,b+f));
    		ans = max(ans,max(c+d,c+e));
     		cout << ans;
			continue;
		}
		if(n==4){
			int a,b,c,d,e,f,g,h,i,j,k,l;
    		cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    		ans = max(a+d+h+k,a+d+h+l);
    		ans = max(ans,max(a+d+i+k,a+d+i+l));
    		ans = max(ans,max(a+e+g+k,max(a+e+g+l,a+e+h+j)));
    		ans = max(ans,max(a+e+h+l,max(a+e+i+j,a+e+i+k)));
    		ans = max(ans,max(a+f+g+k,max(a+f+g+l,max(a+f+h+j,max(a+f+h+k,max(a+f+i+j,a+f+i+k))))));
    		ans = max(ans,max(b+d+g+k,max(b+d+g+l,max(b+d+h+j,max(b+d+h+l,max(b+d+i+j,b+d+i+l))))));
    		ans = max(ans,max(b+e+g+j,max(b+e+g+l,b+e+i+j)));
    		ans = max(ans,max(b+f+g+j,b+f+g+k));
    		cout << ans;
    		continue;
		}
		bool f1 = 1;
    	for(int i = 1;i<=n;i++){
    		cin >> a[i] >> b[i] >> c[i];
    		if(c[i]!=0){
    			f1 = 0;
			}
			if(a[i]!=b[i]){
				f1 = 0;
			}
		}
		if(f1){
			for(int i = 1;i<=n;i++){
				ans+=a[i];
			}
			cout << ans;
			continue;
		}
	}
	return 0;
}