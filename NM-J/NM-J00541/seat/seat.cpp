#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000],s[20][20],ming,k = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ming = a[1];
	sort(&a[1],&a[n*m]+1,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2 == 1){
			for(int j=1;j<=n;j++){
				s[i][j] = a[++k];
				if(s[i][j] == ming){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s[i][j] = a[++k];
				if(s[i][j] == ming){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
