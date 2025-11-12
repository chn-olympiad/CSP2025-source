#include<bits/stdc++.h>
using namespace std;
int a[200],b[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+1+sum,cmp);
	//for(int i=1;i<=n;i++)b[i][1]=a[i];
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				b[i][j]=a[++cnt];
			}
		}else{
			for(int i=1;i<=n;i++){
				b[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==s){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
