#include<bits/stdc++.h>
using namespace std;
int n,m,a[101][101],r,t=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>a[1][1])
			t++;
		}
	}
	int flag=0,fla=t%n;
	if(t%n!=0) flag=1;
	else fla=n;
	if((t/n+flag)%2==0){
		cout<<t/n+flag<<" "<<n-fla+1;
	}
	else{
		cout<<t/n+flag<<" "<<fla;
	}
	return 0;
}