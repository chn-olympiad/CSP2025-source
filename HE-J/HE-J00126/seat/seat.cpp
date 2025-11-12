//T2
#include<bits/stdc++.h>
using namespace std;
int a[50][50],n,m;
int sco[501];
bool cmp(int a,int b){
	return a>b;
}
int poi=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	//point
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=poi;poi++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[j][i]=poi;poi++;
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}            //check0*/
	int ans;
	for(int i=1;i<=n*m;i++){
		cin>>sco[i];if(i==1) ans=sco[i];
	} 
	//cout<<ans<<" ";     //check1;
	sort(sco+1,sco+n*m+1,cmp);
	int poi1=0;
	for(int i=1;i<=n*m;i++){
		if(sco[i]==ans){
			poi1=i;break;
		}
	}
	//cout<<poi1<<endl; //check2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(poi1==a[i][j]) cout<<j<<" "<<i;
		}
	}
	return 0;
}
/*
2 2
97 100 98 99
*/
