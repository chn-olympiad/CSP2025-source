#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int m,n,s,k=1,r;
int a[200];
int b[100][100];
int main(){
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[i][j]=a[k];
				k++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[j][i]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
