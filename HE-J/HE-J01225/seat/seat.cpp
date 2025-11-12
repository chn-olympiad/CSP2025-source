#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
long long n,m,a[105],b[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int t=0,ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				t++;
				if(a[t]==ans){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				t++;
				if(a[t]==ans){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
}
