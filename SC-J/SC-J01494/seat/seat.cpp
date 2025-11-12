#include<bits/stdc++.h>
using namespace std;
int g[105],a[105],mp[15][15];
int p,x,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
			cin>>g[i];	
	}
	x=g[1];
	sort(g+1,g+n*m+1);
	for(int i=1;i<=n*m;i++){
		a[i]=g[n*m-i+1];	
	}
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			p=i;
			break;
		}
	}
	int t=1;
	for(int i=1;i<=n;i++){
		if(i%2==1)
		for(int j=1;j<=m;j++){
			mp[j][i]=a[t];
			t++;
		}
		else 
		for(int j=m;j>=1;j--){
			mp[j][i]=a[t];
			t++;
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<mp[j][i]<<' ';
		cout<<endl;
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
			if(x==mp[j][i])
				cout<<i<<' '<<j;
		}
			
	}
	return 0;
}