#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],s[110],ss,b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int t=s[1];
	sort(s+1,s+n*m+1);
	ss=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=s[ss];
			ss--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==0){
				for(int k=1;k<=m;k++){
					b[m-k+1]=a[i][k];
				}
				for(int k=1;k<=m;k++){
					a[i][k]=b[k];
				}
				i+=1;
				j=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==t){
				cout<<i<<" "<<j;
			}
		}
	}   
	return 0;
}
