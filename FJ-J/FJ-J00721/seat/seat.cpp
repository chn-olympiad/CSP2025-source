#include<bits/stdc++.h>
using namespace std;
struct RQ{
	int a,i;
}x[110];
int cmp(RQ a,RQ b){
	if(a.a>b.a) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm;
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>x[i].a;
		x[i].i=i;
	}
	sort(x+1,x+1+nm,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++)
				if(x[(i-1)*n+j].i==1){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
		}
		else
			for(int j=n;j>=1;j--)
				if(x[(i-1)*n+n-j+1].i==1){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
	}
	return 0;
}

