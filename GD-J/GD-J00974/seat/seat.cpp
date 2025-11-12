#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,mu;
ll b[225];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll l=n*m;
	for(int i=1;i<=l;i++){
		cin>>b[i];
	}
	mu=b[1];
	sort(b+1,b+1+l);
	l++;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(b[--l]==mu){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(b[--l]==mu){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

