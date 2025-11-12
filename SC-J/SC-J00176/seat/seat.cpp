#include<bits/stdc++.h>
using namespace std;
int map[15][15];
int c[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int ans;
	ans=c[1];
	sort(c+1,c+1+n*m,cmp);
	int i=1,j=1;
	int f=1;
	int cnt=0;
	while(1){
		cnt++;
		if(c[cnt]==ans){
			cout<<j<<" "<<i;
			break;
		}
		if(f==1){
			if((i+1)<=n) {
				i++;
			}
			else if((j+1)<=m){
				j++;
				f=2;
			}
		}
		else{
			if((i-1)>=1){
				i--;
			}
			else if((j+1)<=m){
				j++;
			}
		}
	}
	return 0;
}