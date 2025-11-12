#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag=0;
	int num[104];
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
	}
	int uj=num[1];
	int a[12][12];
	for(int i=1;i<=n*m-1;i++){
		for(int j=i;j<=n*m-1;j++){
			if(num[i]<num[i+1])swap(num[i],num[i+1]);
		}
	}
	int l=1;
	for(int i=1;i<=n;i++){
		if(flag==0){
			for(int j=1;j<=m;j++){
				a[i][j]=num[l];
				l++;
			}
		flag++;
		}
		else if(flag==1){
			for(int j=m;j<=1;j--){
				a[i][j]=num[l];
				l++;
			}
		flag--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==uj){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}