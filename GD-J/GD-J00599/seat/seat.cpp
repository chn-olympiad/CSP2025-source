#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
int a[1000],f[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1]; 
	sort(a+1,a+n*m+1,cmp);
	int tot=0,i=0,j=1;
	while(j<=m){
		if(j%2==1){
			while(i+1<=n){
				i++;
				f[i][j]=a[++tot];
			}
		}else{
			while(i-1>=0){
				f[i][j]=a[++tot];
				i--;
			}
		}
		j++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==x){
				cout<<j<<' '<<i<<'\n';
			}
		}
	}
	return 0;
}
