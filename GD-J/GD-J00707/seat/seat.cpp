#include<bits/stdc++.h>
using namespace std;
int n,m,a[15],mp[15][15],ans;
bool flag=1; 
bool cmp(int x,int y){
	return x>y;
}
void ji(){
	int tmp=1;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			mp[j][i]=a[tmp];
			tmp++;
		}
		tmp+=n;
	}
	return;
}
void ou(){
	int tmp=n+1;
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;j--){
			mp[j][i]=a[tmp];
			tmp++;
		}
		tmp+=n;
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	ji();
	ou();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==ans){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
