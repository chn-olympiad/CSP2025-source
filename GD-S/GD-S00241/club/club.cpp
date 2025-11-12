#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;

int t,bumen[4],bm_myd[4];

struct xin{
	int ren,bm,manyidu;
}people[300005];

bool cmp(xin a,xin b){
	return a.manyidu > b.manyidu;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	int result[t];
	for(int x = 0;x < t;++x){
		int n,ge = 0,isjin[100005];
		memset(isjin,0,sizeof(isjin));
		memset(bm_myd,0,sizeof(bm_myd));
		memset(bumen,0,sizeof(bumen));
		cin >> n;
		int erfenyi = n / 2;
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= 3;++j){
				people[ge].ren = i;
				people[ge].bm = j;
				cin >> people[ge].manyidu;
				ge++;
			}
		}
		
		sort(people,people + 3 * n,cmp);
	
		for(int i = 0;i < 3 * n;++i){
			if(bumen[people[i].bm] < erfenyi && isjin[people[i].ren] == 0){
				bumen[people[i].bm]++;
				isjin[people[i].ren] = 1;
				bm_myd[people[i].bm] += people[i].manyidu;
			}
		}
		
		int ans = 0;
		for(int i = 1;i <= 3;++i){
			ans += bm_myd[i];
		} 
		result[x] = ans;
	}
	
	for(int i = 0;i < t;++i){
		cout << result[i] << "\n";
	}
	
	return 0;
} 

