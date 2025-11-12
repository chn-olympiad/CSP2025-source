#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}//zhuangya dp niuB,it may bring me 40 points
	for(int i=1;i<(1<<n);i++){
		int mx=0,tot=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				mx=max(mx,a[j]);//Tmd,I ba j write to i
				tot+=a[j];//I tiao le it 30mins
			}
		}
		if(tot>2*mx){
			cnt++;
		}
	}
	cout<<cnt%998244353;
	return 0;
}//written by zsz0804_/GD-J00722
