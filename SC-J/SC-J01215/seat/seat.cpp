#include<bits/stdc++.h>
using namespace std;
const int N=15,NN=105;
int n,m,a[NN],sc;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>a[i];
	sc=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1;
	for(int i=1,zf=1;i<=n*m&&a[i]!=sc;++i){
		if(x+zf>n||x+zf<1){
			++y;
			zf=-zf;
		}
		else	x+=zf;
	}
	cout<<y<<' '<<x;
	return 0;
} 