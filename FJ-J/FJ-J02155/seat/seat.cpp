#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int b[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//srand(time(0));
	int n,m;
	cin>>n>>m;
	int t1=0;
	cin>>t1;
	b[1]=t1;
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
		//b[i]=rand();
	}
	sort(b+1,b+n*m+1,cmp);
	int t=0;
	for(int i=1;i<=m/2;i++){
		for(int j=1;j<=n;j++){
			t++;
			a[j][i*2-1]=b[t];
		}
		for(int j=n;j>=1;j--){
			t++;
			a[j][i*2]=b[t];
		}
	}
	if(m%2==1){
		for(int i=1;i<=n;i++){
			t++;
			a[i][m]=b[t];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<a[i][j]<<' ';
			//printf("%05d ",a[i][j]);
			if(a[i][j]==t1){
				cout<<j<<' '<<i;
				return 0;
			}
		}
		//cout<<endl;
	}
}
/*
5/2=2;
1234 5
*/
