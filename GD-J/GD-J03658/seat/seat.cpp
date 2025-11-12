#include<bits/stdc++.h>
using namespace std;
int seat[15][15];
struct shh{
	bool ren;
	int chengji;
}a[1000];
bool cmp(shh a,shh b){
	return a.chengji>b.chengji;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].chengji;
		a[i].ren=0;
	}
	a[0].ren=1;
	int ans;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i].ren==1){
			ans=i;
			break;
		}
	}
	int hang=1,lie=1;
	while(ans--){
		if(lie%2==0){
			hang--;
		}else{
			hang++;
		}
		if(hang>n){
			hang=n;
			lie++;
			continue;
		}else if(hang==0){
			hang=1;
			lie++;
			continue;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
