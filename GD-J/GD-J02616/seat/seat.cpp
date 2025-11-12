#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
const long long M=1e2+10;
long long n,m,aa,arr[N],xb=0,a[M][M];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&arr[i]);
	}
	aa=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				xb++;
				a[j][i]=arr[xb];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				xb++;
				a[j][i]=arr[xb];
			}	
		}
	}
	//cout<<aa;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==aa){
				cout<<j<<" "<<i;
				break;
			}
		}
		
	}
	return 0;
} 
