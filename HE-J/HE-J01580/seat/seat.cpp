#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	int num[n*m],p=0;
	int a[n][m];
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>num[i];
	}
	R=num[1];
	sort(num+1,num+l+1);
	for(int i=1;i<=l/2;i++){
		swap(num[i],num[l-i+1]);
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				p++;
				a[i][j]=num[p];
				if(a[i][j]==R){
					cout<<i<<" "<<j;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				p++;
				a[i][j]=num[p];
					if(a[i][j]==R){
					cout<<i<<" "<<j;
				}
			}
		}
		
	}
	return 0;
}
