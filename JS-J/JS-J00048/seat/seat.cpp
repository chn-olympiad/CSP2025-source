#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int b[110];
int cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		b[++cnt]=a[i];
	}
	int wei;
	for(int i=1;i<=cnt;i++){
		if(b[i]==ans){
			wei=i;
			break;
		}
	}
	int lie=wei/n+1;
	int hang=wei%n;
	if(hang==0){
		lie--;
		if(lie%2==1){
			cout<<lie<<" "<<m;
		}
		else{
			cout<<lie<<" "<<1;
		}
	}
	else{
		if(lie%2==1){
			cout<<lie<<" "<<hang;
		}
		else{
			cout<<lie<<" "<<n-hang+1;
		}
	}
	cout<<endl;
	return 0;
}
