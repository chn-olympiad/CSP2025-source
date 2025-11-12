#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=1,grade[15][15],a[10005];
bool cmp(int a,int b){
	return b<a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				grade[i][j]=a[cnt];  //座位表第i列第j行为第cnt名考生 
				cnt++;
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				grade[i][j]=a[cnt];  //座位表第i列第j行为第cnt名考生 
				cnt++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(grade[i][j]==k)  cout<<i<<" "<<j;
		}
	}
	return 0;
}
