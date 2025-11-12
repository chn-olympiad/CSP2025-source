#include<iostream>
#include<algorithm>
using namespace std;
#define long long ll
int n,m,ans[15][15],a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ip_score=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=1;
	int j=1,k=1;
	for(int i=1;i<=n*m;i++){
		if(k%2!=0&&j!=n){
			ans[j][k]=a[i];
			j++;
		}
		else if(k%2!=0&&j==n){
			ans[j][k]=a[i];
			k++;
		}
		else if(k%2==0&&j!=1){
			ans[j][k]=a[i];
			j--;
		}
		else if(k%2==0&&j==1){
			ans[j][k]=a[i];
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==ip_score) cout<<j<<' '<<i;
		}
	}
	return 0;
}