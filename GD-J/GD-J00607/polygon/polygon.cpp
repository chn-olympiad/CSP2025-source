#include<iostream>
using namespace std;

int popc(int x){
	int ans = 0;
	while(x){
		if(x&1) ans++;
		x/=2;
	}
	return ans;
}


int lon[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;int cnt = 0;
	for(int i=1;i<=n;i++)cin>>lon[i];
	for(int i=0;i<(1<<n);i++){
		if(popc(i) < 3)continue;
		int q = i;
		int maxl = 0,sums = 0;int cx = 1;
		while(q){
			if(q&1){
				maxl = max(maxl,lon[cx]);
				sums += lon[cx];
			}
			q/=2;cx++;
		}
		if(sums > maxl*2)cnt++;
	}
	cout<<cnt;
	return 0;
}
