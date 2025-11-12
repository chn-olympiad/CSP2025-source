#include<bits/stdc++.h>
using namespace std;
const int N = 10100;
int aa[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	int tp = 0; 
	for(int k = 1; k <= T; k++){
		tp++;
		int n;
		cin>>n;
		int a[N][4];
		int w[N];
		int f = n/2;
		for(int i = 1; i <= n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int t1 = 0, t2 = 0, t3 = 0;
		for(int i = 1; i <= n; i++){
			if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][1]){
				t1++;
			} 
			if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][2]){
				t2++;
			} 
			if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][3]){
				t3++;
			} 
		}
		
		if((t1<=n/2) && (t2<=n/2) && (t3<=n/2)){
			w[1] = max(max(a[1][1],a[1][2]),a[1][3]);
			for(int i = 2; i <= n; i++){
				w[i] = w[i-1]+max(max(a[i][1],a[i][2]),a[i][3]);
			}
			aa[tp] = w[n];
		}else {
			int ans = 0;
			int s1[N],s2[N],s3[N];
			//1 -----------------------------------------
			for(int i = 1; i <= n; i++){
				if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][1]){
					s1[i] = 1;
				} 
			}
			for(int i = 1; i <= n/2; i++){
				int maxn = 0, mm = 0;
				for(int j = 1; j <= n; j++){
					if(s1[j] == 1 && a[j][1] > maxn){
						maxn = a[j][1];
						mm = j;					
					}
				}
				ans+=maxn;
				s1[mm] = 0;
				a[mm][2] = a[mm][3] = 0;
			}
			for(int i = 1; i <= n; i++){
				if(s1[i] == 1){
					a[i][1] = 0;
				}
			}
			//2-------------------------------------------
			for(int i = 1; i <= n; i++){
				if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][2]){
					s2[i] = 1;
				} 
			}
			for(int i = 1; i <= n/2; i++){
				int maxn = 0, mm = 0;
				for(int j = 1; j <= n; j++){
					if(s2[j] == 1 && a[j][2] > maxn){
						maxn = a[j][2];
						mm = j;					
					}
				}
				ans+=maxn;
				s2[mm] = 0;
				a[mm][2] = a[mm][3] = 0;
			}
			for(int i = 1; i <= n; i++){
				if(s2[i] == 1){
					a[i][2] = 0;
				}
			}
			//3--------------------------------------------
			for(int i = 1; i <= n; i++){
				if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][3]){
					s3[i] = 1;
				} 
			}
			for(int i = 1; i <= n/2; i++){
				int maxn = 0, mm = 0;
				for(int j = 1; j <= n; j++){
					if(s3[j] == 1 && a[j][3] > maxn){
						maxn = a[j][3];
						mm = j;					
					}
				}
				ans+=maxn;
				s3[mm] = 0;
				a[mm][2] = a[mm][1] = 0;
			}
			for(int i = 1; i <= n; i++){
				if(s3[i] == 1){
					a[i][3] = 0;
				}
			}
			aa[tp] = ans;
		}
	}
	for(int i = 1; i <= T; i++){
		cout<<aa[i]<<endl;
	}
	return 0;
}