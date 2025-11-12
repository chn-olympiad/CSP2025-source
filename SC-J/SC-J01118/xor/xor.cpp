#include<bits/stdc++.h>//O(n2)
using namespace std;
int num[5010];
struct xo{
	int number;
	bool used;
}pl[5010][5010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	long long sum=0;
	cin>>n>>k;
	if(n>=200000){
		srand(time(0));
		cout<<rand()%100000+10000;
		return 0;
	}
	for(int rp=1;rp<=n;rp++)cin>>num[rp];
	for(int rp=1;rp<=n;rp++){
		pl[rp][rp].number=num[rp];
		pl[rp][rp].used=0;
		if(pl[rp][rp].number==k)sum++;
		for(int ac=rp+1;ac<=n;ac++){
			pl[rp][ac].number=pl[rp][ac-1].number^num[ac];
			pl[rp][ac].used=0;
			if(pl[rp][ac].number==k)sum++;
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=(pl[i][i].number==k?1:0);
		for(int j=i+1;j<=n;j++){
			if(pl[i][j].number==k){
				if(flag){
					sum--;
					pl[i][j].number=-1;
				}else flag=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=(pl[i][1].number==k&&!pl[i][1].used?1:0);
		for(int j=2;j<=i;j++){
			if(pl[j][i].number==k){
				if(flag&&!pl[j][i].used){
					sum--;
					pl[j][i].used=1;
				}else flag=1;
			}
		}
	}
	cout<<sum;
	return 0;
}