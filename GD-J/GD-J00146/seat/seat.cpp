#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,g[N],ans;
void find(){
	int wl=ans/n+1;
	int wh;
	wh=n-(ans-ans/n*n);
	cout<<wl<<" "<<wh;
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=m*n;i++){
		cin>>g[i];
		if(g[i]>g[1]){
			ans++;
		}
	}
	find();
	return 0;
}
