#include<bits/stdc++.h>
using namespace std;
const int N=12;
int a[N*N],flag[2];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,index=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2==0){
		for(int i=n;i>=1;i--){
			if(a[index]==ans){
				flag[1]=i;
				flag[0]=j;
			}
			index++;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[index]==ans){
				flag[1]=i;
				flag[0]=j;
			}
			index++;		
		}
	}	
}
	cout<<flag[0]<<" "<<flag[1];
	return 0;
}
