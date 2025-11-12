//2 2
//98 99 100 97
/*
2 2
98 99 100 97
*/
#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],arr[1005][1005];
set <int> st;
bool cmp(const int &a1,const int &b){
	return a1>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin >> a[i][j]; 
		}
	}
	ans=a[1][1]; 
	bool mode=1;
	for (int i=1;i<=m;i++){
		for (int 
		j=1;j<=n;j++){
			int Max=-INT_MAX;
			for (int k=1;k<=n;k++){
				for (int l=1;l<=m;l++){
					if (st.count(a[k][l])==0){
						Max=max(Max,a[k][l]); 
					}
				}
			}
			st.insert(Max);
			arr[i][j]=Max;
		}
	}  
	for (int i=1;i<=m;i++){
		int x=1;
		if (i%2==0){
			for (int j=n;j>=1;j--){
			if (arr[i][j]==ans){
					cout << i << " " << x;
					return 0;
				}
				x++;
			}
		}else{
			for (int j=1;j<=n;j++){
				if (arr[i][j]==ans){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
