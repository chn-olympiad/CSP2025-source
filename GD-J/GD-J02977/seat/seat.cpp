#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1010],MAP[110][110];
bool cmp(ll a,ll b){
	return a>b;
}
//#Shang4Shan3Ruo6Shui4
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ll ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans) ans=i;
	}
	ll sum=1,c=1,r=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				MAP[j][i]=a[sum];
				sum++;
			}
		}else{
			for(int j=m;j>=1;j--){
				MAP[j][i]=a[sum];
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(MAP[i][j]==a[ans]) c=j,r=i;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
