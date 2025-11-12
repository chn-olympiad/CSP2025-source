#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t[1000];
	for(int i=1;i<=n*m;i++){
		cin>>t[i];
	}
	int ansd=t[1];
	sort(t+1,t+1+n*m,cmp);
	int a[20][20];
	int x=1;

	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=t[x];
				//cout<<"("<<j<<" "<<i<<")"<<"->"<<t[x];
				x++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=t[x];
				//cout<<"("<<j<<" "<<i<<")"<<"->"<<t[x];
				x++;

			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==ansd){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
