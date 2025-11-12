#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110],b[110][110];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,aa,k=1;
	cin>>n>>m>>aa;
	a[1]=aa;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[j][i]=a[k++];
		}i++;
		for(int j=n;j>=1;j--){
			b[j][i]=a[k++];
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==aa){
				cout<<j<<" "<<i;
				break;
			}
		}
	}	
	
	return 0;
}
