#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5 + 5;
int T,n,a[N][3],c[N][3],d[N],b[3],e[3],maxx,minn,k,tre,num;
ll sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int o = 1 ; o <= T ; o++){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			maxx = -1;
			minn = 1e7;
			tre = 0;
			for(int j = 0 ; j < 3 ; j++){
				maxx = max(maxx,a[i][j]);
				if(maxx == a[i][j]){
					tre=j;
				}
			}
			for(int j = 0 ; j < 3 ; j++){
				if(j != tre){
					minn = min(minn,maxx-a[i][j]);
				}
			}
			sum += maxx;
			c[e[tre]++][tre] = minn;
			b[tre]++;
		}
		num = -1;
		tre = 0;
		for(int j = 0 ; j < 3 ; j++){
			num = max(b[j],num);
			if(num == b[j]){
				tre=j;
			}
		}
		if(num <= n/2){
			cout << sum << endl;
		}
		else{
			num -= n/2;
			for(int i = 0 ; i < e[tre] ; i++){
				d[i] = c[i][tre];
			}
			sort(d,d+e[tre]);
			for(int i = 0 ; i < num ; i++){
				sum -= d[i];
			}
			for(int i = 0 ; i < e[tre] ; i++){
				d[i] = 1e7;
			}
			cout << sum << endl;
		}
		sum = 0;
		for(int i = 0 ; i <= 2; i++){
			e[i] = 0;
			b[i] = 0;
		} 
		
	}
	return 0;
}
