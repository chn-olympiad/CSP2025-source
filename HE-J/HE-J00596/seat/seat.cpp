# include<bits/stdc++.h>
using namespace std;
int n,m,r,summ;
int a[110];
bool q[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		q[a[i]]=1;
	}
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[n*m-++summ+1]==r) cout<<i<<" "<<j;
		}
		i++;
		for(int j=n;j>=1;j--){
			if(a[n*m-++summ+1]==r) cout<<i<<" "<<j;
		}
	}
	return 0;
}
