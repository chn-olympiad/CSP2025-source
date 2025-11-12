#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s[11][11],ai,ac;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ac=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	//cout<<endl;
	for(int k=1;k<=m;k+=2){
		if(k+1>m)break;
		for(int i=1;i<=n;i++){
			ai++;
			s[i][k]=a[ai];
		}
		for(int i=n;i>=1;i--){
			ai++;
			s[i][k+1]=a[ai];
		}
	}
	if(m%2==1){
		for(int i=1;i<=n;i++){
			ai++;
			s[i][m]=a[ai];
			//cout<<a[ai]<<' '<<ai<<endl;
		}
		//cout<<endl;
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=m;j++){
	//		cout<<s[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==ac){
				cout<<j<<' '<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
