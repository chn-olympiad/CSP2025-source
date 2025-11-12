#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11];
int grades[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int xiaoR;
	for(int i=1;i<=n*m;i++){
		cin>>grades[i];
		if(i==1){
			xiaoR=grades[i];
		}
	}
	sort(grades+1,grades+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		swap(grades[i],grades[n*m-i+1]);
	}
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				k++;
				a[j][i]=grades[k];
			}
		}else{
			for(int j=1;j<=n;j++){
				k++;
				a[j][i]=grades[k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==xiaoR){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		} 
	}
}
