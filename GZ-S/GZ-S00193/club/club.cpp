#include <bits/stdc++.h>
using namespace std;
//GZ-S00193 南明区山水中学 徐梓赫 
const int N = 1e5+20;
long long n,t,x,cnt,s = INT_MIN; 
int sx[5];
int a[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 1;i<=t;i++){
		s = INT_MIN;
		cnt = 0;
		cin>>n;
		x = n/2;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i = 1;i<=n;i++){
			/*if(sx[1] == x){
				for(int k = 1;i<=n;i++){
					a[k][1] = 0;
				} 
			}
			if(sx[2] == x){
				for(int k = 2;i<=n;i++){
					a[k][2] = 0;
				} 
			}
			if(sx[3] == x){
				for(int k = 1;i<=n;i++){
					a[k][3] = 0;
				} 
			}*/
			cnt+=max(max(a[i][1],a[i][2]),a[i][3]);
			/*if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][1]){
				sx[1]++;
			}
			else if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][2]){
				sx[2]++;
			}
			else if(max(max(a[i][1],a[i][2]),a[i][3]) == a[i][3]){
				sx[3]++;
			}*/
			
		}
		s = max(s,cnt);
		cout<<s<<"\n";
	}
	return 0;
}

