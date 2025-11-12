#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100],b[100][100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ans=a[0];
	sort(a,a+n*m,cmp);
	int cnt=0,f=0;
	for(int i=1,j=1;;){
			if(cnt>=n*m){
				break;
			}
			if(i==n+1){
				j++;
				i=n;
				f++;
			}else if(i==0){
				j++;
				i=1;
				f++;
			}
			b[i][j]=a[cnt];
			cnt++;
			if(f%2==0){
			    i++;
			}else if(f%2!=0){
				i--;
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
