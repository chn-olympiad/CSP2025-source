#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+10;
int a[N],d[15][15];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int b=n*m;
	int cnt=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			a[++cnt]=d[i][j];
		}
	}
	int c=a[1];
	sort(a+1,a+1+b);
	for(int i=1;i<=m;i++){		
			if(i%2==0){
				for(int j=n;j>=1;j--){
					d[i][j]=a[cnt];
					cnt--;
				}
			}else{
				for(int j=1;j<=n;j++){
					d[i][j]=a[cnt];
					cnt--;
				}
			}	
	}
	for(int i=1;i<=m;i++){		
		for(int j=1;j<=n;j++){			
			if(d[j][i]==c){
				cout<<j<<" "<<i;
			}		
		}	
	}
	return 0;
}
