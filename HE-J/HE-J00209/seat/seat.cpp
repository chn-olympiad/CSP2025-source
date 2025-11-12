#include <bits/stdc++.h>
using namespace std;
int n,m;
int s;
int rk=1;
int a[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>s) rk++;
	}
	int num=0;
	bool r=0;
	int i,j;
	for(i=1;i<=m;i++){
		if(i&1){
			for(j=1;j<=n;j++){
				num++;
				a[j][i]=num;
				if(num==rk){
					r=1;
					break;		
				}
			}
		}else{
			for(j=n;j>=1;j--){
				num++;
				a[j][i]=num;
				if(num==rk){
					r=1;
					break;
				}
			}
		}
		if(r) break;
	}
	cout<<i<<" "<<j;
	return 0;
}
