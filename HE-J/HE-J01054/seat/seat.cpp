#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	cin>>n>>m;
	int o[100][100];
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				o[j][i]=k;
				k++;
			}
		}else{
			for(int j=m;j>=1;j--){
				o[j][i]=k;
				k++;
			}
		}
	}
	int a[100],a1,v;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			v=i;
			break;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v==o[i][j]){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}

