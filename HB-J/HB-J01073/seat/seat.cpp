#include <bits/stdc++.h>
using namespace std;
bool kp(int a,int b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[10010],an;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	an=a[1];
	sort(a+1,a+n*m+1,kp);
	int ji=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ji++;
				if(a[ji]==an){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ji++;
				if(a[ji]==an){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
