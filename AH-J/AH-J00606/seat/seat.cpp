#include<bits/stdc++.h>
using namespace std;
int c[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>c[i];
	int x=c[1];
	sort(c+1,c+1+n*m,cmp);
	int ans=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(c[ans]==x){
					cout<<j<<" "<<i;
					return 0;
				}
				ans++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(c[ans]==x){
					cout<<j<<" "<<i;
					return 0;
				}
				ans++;
			}
		}
	}
	if(m%2==1)
		cout<<m<<" "<<n;
	else
		cout<<m<<" "<<1;
	return 0;
}
