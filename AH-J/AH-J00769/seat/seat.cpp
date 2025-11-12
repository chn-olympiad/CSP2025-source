#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans;
int a[1000],t[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[1];
		}
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans++;
				t[i][j]=a[ans];
			}	
		}else{
			for(int j=n;j>=1;j--){
				ans++;
				t[i][j]=a[ans];
			}
		}	
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(t[i][j]==x){
				cout<<i<<" "<<j;
			}
		}	
	}	
	return 0;
}
