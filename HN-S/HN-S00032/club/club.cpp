#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int a[N][4] , tot , now;
int best[N][4];
int best2[N][4]; 
int list[N];
int id[N];
bool cnt[4];
int maxn[4];
long long ans;
int find(int a,int b,int c,int k){
	if(cnt[1]==0&&k==a){
		cnt[1]++;
		return 1;
	}
	if(cnt[2]==0&&k==b){
		cnt[2]++;
		return 2;
	}
	if(cnt[3]==0&&k==c){
		cnt[3]++;
		return 3;
	}
}//
void msort(int a,int b,int c,int k){
	int z[3];
	z[0] = a;
	z[1] = b;
	z[2] = c;
	sort(z,z+3);
	for(int i = 1;i <= 3;i++){
		cnt[i] = 0;
	}
	for(int i = 0 ;i<=2;i++){	
		best[k][find(a,b,c,z[i])] = z[i];
		best2[k][3-i] = z[i];
	}
}
int find2(int k,int r){
	for(int i = 1;i <= 3;i++){
		if(best[r][i]==k)
		return i;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n , t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		ans = 0; 
		memset(maxn,0,sizeof(maxn));
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= 3;k++){
				cin >> a[j][k];	
			}
			msort(a[j][1],a[j][2],a[j][3],j);		
		}
		for(int j = 1;j <= n;j++){
			int w = find2(best2[j][1],j);
			int w2 = find2(best2[j][2],j);
			if(maxn[w] < n/2){
				ans += best2[j][1];
				maxn[w]++;
			}
			else{
				ans += best2[j][2];
				maxn[w2]++;
			}
		}
		cout<<ans<<'\n';
//	for(int j = 1;j <= n;j++){
//		cout<<best2[j][1]<<' ';
//	}
//	cout<<endl;
//	for(int j = 1;j <= n;j++){
//		cout<<find2(best2[j][1],j)<<' ';
//	}
//	cout<<endl;
	}
	
	return 0;
} 
