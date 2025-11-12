#include <bits/stdc++.h>
using namespace std;
struct lie{
	int w[15];
} x[15];
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1]={0};
	int mark_R;
	cin>>mark_R;
	a[1]=mark_R; 
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				x[i].w[j]=a[j+(i-1)*m];
			}
		}else{
			for(int j=n;j>=1;j--){
				x[i].w[j]=a[j+(i-1)*m];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i].w[j]==mark_R){
				cout<<i<<' '<<j;
			}
		}
	}
	cout<<endl;
	return 0;
}

