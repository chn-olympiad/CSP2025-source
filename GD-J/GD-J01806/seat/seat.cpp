#include<bits/stdc++.h>
using namespace std;
const int N=110;
long long a[N],R,pai,l,h;
long long p[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1);
	long long cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int k=1;k<=n;k++){
				p[k][j] = a[cnt-n+1];
				cnt++;
			}	
		}
		else{
			for(int k=1;k<=n;k++){
				p[k][j] = a[n*m-cnt];
				cnt++;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]==R){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//偶数列从小到大，奇数列从大到小
// 
