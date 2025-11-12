#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long b[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tep=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tep=a[1];
	sort(a+1,a+n*m+1);
	int tep3=0;
	for(int i=n*m;i>=1;i--){
		tep3++;
		if(a[i]==tep){
			tep=tep3;
			break;
		}
	}
	int tep2=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				tep2++;
				if(tep2==tep){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				tep2++;
				if(tep2==tep){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		if(tep2==tep){
			break;
		}
	}
	return 0;
}
