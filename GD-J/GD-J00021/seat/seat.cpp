#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[105];
long long ans[15][15];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	long long d=a[1];
	long long cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;++i){
		if(i%2==1){
			for(int j=1;j<=n;++j){
				cnt++;
				ans[j][i]=a[cnt];
			}
		}
		else{
			for(int j=n;j>=1;--j){
				cnt++;
				ans[j][i]=a[cnt];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			
			if(ans[i][j]==d){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
} 
