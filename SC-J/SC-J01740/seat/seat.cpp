#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			int pos=(j-1)*n+i;
			if(a[pos]==ans){
				if(j&1){
					cout<<j<<' '<<i;
					return 0;
				}
				else{
					cout<<j<<' '<<n-i+1;
					return 0;
				}
			}
		}
	}
	return 0;
} 
/*
密码：#Shang4Shan3Ruo6Shui4
3 3
94 95 96 97 98 99 100 93 92

*/