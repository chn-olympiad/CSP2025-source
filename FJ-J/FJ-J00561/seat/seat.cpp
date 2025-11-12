#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1],R,b,s=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b;
			if(i==1&&j==1){
				R=b;
			}
			else{
				if(b>R)s++;
			}
		}
	}
	int l=ceil(s/(n*1.0)),h;
	if(l%2==1){
		h=s%n;
	}
	else h=n-s%n+1;
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
