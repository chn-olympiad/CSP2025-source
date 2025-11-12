#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>=a[1][1])sum++;
		}
	} 
	int s1=sum/(2*n),s2=sum%(2*n);
	if(s2==0)cout<<s1*2<<" "<<1;
	else if(s2<=n)cout<<s1*2+1<<" "<<s2;
	else cout<<s1*2+2<<" "<<2*n-s2+1;
	return 0;
} 
