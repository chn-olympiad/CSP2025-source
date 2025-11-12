#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
const int MOD = 998244353;
int mx = -1, ans;
int stick[N], sum[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &stick[i]);
		mx = max(mx, stick[i]);
	} 
	if (n==1 || n==2){
		printf("0\n");
	}else if(n==3){
		printf("1\n");
	}else if(n==4){
		for (int i=0; i<=4; i++){
			for (int j=0; j<=4; j++){
				for (int k=0; k<=4; k++){
					for (int x=0; x<=4; x++){
						if (i!=j && i!=k && i!=x && j!=k && j!=x && k!=x){
							if (i==0){
								mx = max(j, max(k, x));
							}else if(j==0){
								mx = max(i, max(k, x));
							}else if(k==0){
								mx = max(j, max(i, x));
							}else if(x==0){
								mx = max(j, max(k, i));
							}
							if (stick[i]+stick[j]+stick[k]+stick[x]>2*mx) ans++;
						}
					}
				}
			}
		}
		cout << ans%MOD << '\n';
	}
	return 0;
}
