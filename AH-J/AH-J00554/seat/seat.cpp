#include<bits/stdc++.h>
using namespace std;
struct ct{
	int s,i;
}f[105];
int m,n,cnp;
bool cmp(ct x,ct y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i].s;
		f[i].i=i;
	}
	sort(f+1,f+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f[++cnp].i==1){
				cout<<i<<" ";
				if(i%2==1) cout<<j;
				else cout<<n-j+1;
			}
		}
	}
}
