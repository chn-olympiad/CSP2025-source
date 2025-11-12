#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005][10005],f[100005],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>f[i];
	}
	long long x=f[1];
	for(long long i=1;i<=n*m;i++){
		for(long long j=i+1;j<=n*m;j++){
			if(f[i]<f[j]){
				long long q=f[i];
				long long w=f[j];
				f[i]=w;
				f[j]=q;
			}
		}
	}
	cnt++;
	for(long long i=1;i<=n;i++){
		if(i%2==1){
			for(long long j=1;j<=m;j++){
				a[i][j]=f[cnt];
				cnt++;
				if(a[i][j]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(long long j=m;j>=1;j--){
				a[i][j]=f[cnt];
				cnt++;
				if(a[i][j]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
