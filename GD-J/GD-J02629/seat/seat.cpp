#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m; 
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int d=a[1];
	sort(a+1,a+n*m+1);
	int k=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			k=i;
			break;
		}
	}
	k=n*m+1-k;
	int u1=k/n;
	int u2=k-u1*n;
	int x;
	if(n==1) cout<<k<<' '<<1;
	else if(m==1) cout<<1<<' '<<k;
	else{
		if(u1%2==1){
			x=n;
		}else{
			x=1;
		}
		if(u2==0) cout<<u1<<' '<<x;
		else if(x==n) cout<<u1+1<<' '<<x+1-u2;
		else cout<<u1+1<<' '<<u2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
