#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,R,ans,mp[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	/*
	for (int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	*/
	int cnt=1;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			mp[j][i]=a[cnt];
			if (a[cnt]==R){
				cout<<i<<" "<<j;
			}
			cnt++;
		}
		i++;
		for (int j=n;j>=1;j--){
			mp[j][i]=a[cnt];
			if (a[cnt]==R){
				cout<<i<<" "<<j;
			}			
			cnt++;
		}
	}
	/*
	cout<<"\n";
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	return 0;
} 
