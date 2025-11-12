#include<bits/stdc++.h>
using namespace std;
long long a[1006],b[1006],m,n,p[105][105],A,cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	A=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		a[i]=b[n*m-i+1];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(i%2==1){
				p[j][i]=a[cnt];
				if(A==p[j][i]){
					cout<<i<<" "<<j;
				}
			}else{
				p[n-j+1][i]=a[cnt];
				if(A==p[n-j+1][i]){
					cout<<i<<" "<<n-j+1;
				}
			}
		}
	}
	return 0;
}
