#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[100010],a[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>b[i];
	}
	int vis=b[1],num=c;
	sort(b+1,b+c+1);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[j][i]=b[num];
				num--;
			}
		}else{
			for(int j=m;j>=1;j--){
				a[j][i]=b[num];
				num--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==vis){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
