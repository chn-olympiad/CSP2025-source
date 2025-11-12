#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i = 0;i<n;i++){
		for(long long j = 0;j<m;j++){
			if(j==0&&i==0) cin>>a;
			else{
				int x;
				cin>>x;
				if(x>a){
					sum++;
				}
			}
		}
	}
	cout<<sum/n+1;
	if((sum/n+1)&1==1) cout<<" "<<sum%n+1;
	else cout<<" "<<n-(sum%n);
	return 0;
}

