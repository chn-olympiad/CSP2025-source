#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x<y){
		return false;
	}
	return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int f[101]={0};
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> f[i];
	}
	int ans=f[1],c=n*m;
	for(int i=c;i>=1;i--){
		for(int j=1;j<i;j++){
			if(f[j]<f[j+1]){
				swap(f[j],f[j+1]);
			}
		}
	}
	int k=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(f[k]==ans){
					cout << j << " " << i << endl;
					return 0;
				}
				k++;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(f[k]==ans){
					cout << j << " " << i << endl;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
