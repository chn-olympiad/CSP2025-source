#include<bits/stdc++.h>
using namespace std;
int a[101],ans[11][11],cnt=1,j,a1; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+l+1);
	for(int i=1;i<=n;i++){
		if(cnt%2==1){
			for(j=1;j<=m;j++){
				if(a[l]==a1){
					cout<<i<<" "<<j;
					return 0;
				}
				l--;
			}
		}else{
			for(j=m;j>=1;j--){
				if(a[l]==a1){
					cout<<i<<" "<<j;
					return 0;
				}
				l--;
			}
		}
		
	}
	return 0;
}
