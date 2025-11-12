#include <bits/stdc++.h>
using namespace std;

int zong, ans, a[10086],b[10086],c[10086],s,ad,bd,cd,ar[10086],br[10086],cr[10086];
int f(int a,int b){
    return a > b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int s;
	cin >> s;
	while(s--){
        ans = 0;
		int p;
		cin >> p;
		zong = p / 2;
		for(int i = 0; i < p; i++){
			cin >> a[i] >> b[i] >> c[i];
            if(a[i] > b[i]&& a[i] > c[i]){
                ar[ad] = a[i];
                a[i] = 0;
                ad++;
            }else if(b[i] > c[i]){
                br[bd] = b[i];
                b[i] = 0
                bd++;
            }else{
                cr[cd] = c[i];
                c[i] = 0;
                cd++;
            }
        sort(ar, ar + p, f);
        sort(br, br + p, f);
        sort(cr, cr + p, f);
		}
		for(int i = 0; i < zong; i++){
            ans = ans + ar[i];
		}
		for(int i = 0; i < zong; i++){
            ans = ans + br[i];
		}
		for(int i = 0; i < zong; i++){
            ans = ans + cr[i];
		}
            cout << ans;
		}

	return 0;
}
