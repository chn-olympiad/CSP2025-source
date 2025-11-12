#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s[110][110],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+num+1);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				s[i][j]=a[num--];
			}
		}
		else{
			for(int i=n;i>=1;i--){
				s[i][j]=a[num--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}