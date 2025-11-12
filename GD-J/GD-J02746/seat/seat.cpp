#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,a1,an,st=1;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>an;
			if(i==1&&j==1){
				a1=an;
				continue;
			}
			if(an>a1) st++;
		}
	
	int ansn,ansm;
	if(st<n) ansm=1;
	else if(st==n*m) ansm=m;
	else ansm=(st/n)+1;
	if(ansm%2==0) ansn=n-(st-(ansm-1)*n)+1;
	else ansn=st-(ansm-1)*n;
	
	cout<<ansm<<' '<<ansn;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
