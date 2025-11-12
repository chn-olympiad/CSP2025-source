#include<bits/stdc++.h>
using namespace std;
int n,m;
int ma[15][15],a[150],r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
		}
	}
	int c=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ma[j][i]=c;
			c++;
		}
		i++;
		for(int j=n;j>=1;j--){
			ma[j][i]=c;
			c++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ma[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
} 
