#include <bits/stdc++.h>
using namespace std;
int num[150];
int a[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen ("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	cin>>x;
	num[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n*m,cmp);
	bool f=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(f==0){
			for(int j=1;j<=n;j++){
				a[j][i]=num[++cnt];
			}
			f=1;
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=num[++cnt];
			}
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout <<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
	
} 
