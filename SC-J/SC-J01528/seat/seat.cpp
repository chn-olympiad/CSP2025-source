#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[105],s[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(s[cnt]==a[1]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(s[cnt]==a[1]){
					cout<<i<<" "<<j;
					return 0;
				}
			} 
		}
	}
	
	return 0;
}

