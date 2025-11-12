#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],s[105],ans=1,num,r;
bool cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	s[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
	}
	sort(s+1,s+n*m+1,cnt);
	for(int i=1;i<=n*m;i++){
		if(s[i]==r){
			num=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=ans;
				if(ans==num){
					cout<<i<<" "<<j;
					return 0;
				}
				ans++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[i][j]=ans;
				if(ans==num){
					cout<<i<<" "<<j;
					return 0;
				}
				ans++;
			}
		}
	}
	return 0;
}

