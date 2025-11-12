#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
#define ll long long

ll n,m,cct,kks;
string s;
int u[1005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>u[i];
	}
	kks=u[1];
	cct=1;
	sort(u+1,u+n*m+1,cmp);
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(u[cct]==kks){
				cout<<j<<' '<<i;
				return 0;
			}
			cct++;
		}
		j++;
		for(int i=m;i>=1;i--){
			if(u[cct]==kks){
				cout<<j<<' '<<i;
				return 0;
			}
			cct++;
		}
	}
	return 0;
}