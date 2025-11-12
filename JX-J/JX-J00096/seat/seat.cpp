#include <bits/stdc++.h>
using namespace std;
int n,m,a[11][11],cheng[101],k,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	cin >>r;
	cheng[1]=r;
	for(int i=2;i<=n*m;i++) cin >>cheng[i];
	sort(cheng,cheng+n*m+1);
	int k=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(cheng[k]==r){
					cout <<i<<" "<<j;
					return 0;
				}
				k--;
			}	
		}
		else{
			for(int j=1;j<=n;j++){
				if(cheng[k]==r){
					cout <<i<<" "<<j;
					return 0;
				}
				k--;
			}	
		}
	}
	
	return 0;
}
