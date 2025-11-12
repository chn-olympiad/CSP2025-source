#include <bits/stdc++.h>
using namespace std;

int n,t,a[10001][4],cnt2 = 0,d[4],temp = 0;

void dfs(int h,int o); 

void init(){
	cnt2 = 0;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	d[1]=0;
	d[2]=0;
	d[3]=0;
	temp = 0;
	dfs(1,1);
	//sort(ans,ans+10001);
	cout << temp << endl;
}
void dfs(int h,int o){
	
	if (h > n){
		if (cnt2 > temp){
			temp = cnt2;
		}
		//ans[o] = cnt2;
		//cout << cnt2 << endl;
		return;
	}
	for(int i = 1;i<=3;i++){
		if(d[i] < n/2){
			cnt2+=a[h][i];
			d[i]++; 
			dfs(h+1,o);
			d[i]--;
			o++;
			cnt2-=a[h][i];
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	for (int i = 1;i <= t;i++){
		init();
	}
	
	return 0;
}
