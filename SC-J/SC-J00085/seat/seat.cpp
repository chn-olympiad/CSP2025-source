#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int ming=b[1];
	sort(b+1,b+n*m+1,cmp);
	int step=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				step++;
				if(b[step]==ming){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				step++;
				if(b[step]==ming){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 