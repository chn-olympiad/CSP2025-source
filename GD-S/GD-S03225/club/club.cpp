#include<bits/stdc++.h>

using namespace std;

struct members{
	int	num, a1, a2, a3, st=0;
}; 

members d[100005];
int t, n, ans[6];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	for (int i=0; i<t; i++){
		cin >> n;
		if(n>1000) {
			int a1[100005], a2, a3;
			for (int j=0; j<n; j++) cin >> a1[j] >> a2 >> a3;
			sort(a1, a1+n);
			for (int j=n-1; j>n/2-1; j--) ans[i]+=a1[j];
		}
		else if (n>100) {
			int a3;
			for (int j=0; j<n; j++) cin >> d[j].a1 >> d[j].a2 >> a3;
			int n1=0, n2=0;
			for (int j=0; j<n; j++){
				if (n2>=n/2 || (d[j].a1 > d[j].a2 && n1<=n/2)){
					ans[i]+=d[j].a1;
					n1+=1;
				}
				else {
					ans[i]+=d[j].a2;
					n2+=1;
				}
			}
		}
	}
	
	
	for (int i=0; i<t; i++) cout << ans[i] << endl;
	
	
	return 0;
}
