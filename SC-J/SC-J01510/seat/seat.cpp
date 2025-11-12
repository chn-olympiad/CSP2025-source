#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int vis;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			vis=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	int paiming;
	for(int i=1;i<=n*m;i++){
		if(vis==a[i]){
			paiming=n*m-i+1;
		}
	}
	int hang=paiming%n;
	int lie;
	if(hang==0){
		lie=paiming/n;
		hang=n;
	}else{
		lie=paiming/n+1;
	}
	if(lie%2==0){
		cout<<lie<<" "<<n-hang+1<<endl;
	}else{
		cout<<lie<<" "<<hang<<endl;
	}
	return 0;
}