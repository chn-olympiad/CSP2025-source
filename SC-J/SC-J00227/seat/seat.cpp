#include<bits/stdc++.h>
using namespace std;
const int N=12;
int n,m;
int a[N][N];
int cj[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	int bj_val=cj[1],sta;
	sort(cj+1,cj+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(cj[i]==bj_val){
			sta=n*m-i+1;
		}
	}
	int ls,ps;
	ls=(sta-1)/n+1;
	if(ls%2==0){
		ps=n-(sta-1)%n;
	}
	else{
		ps=(sta-1)%n+1;
	}
	cout<<ls<<' '<<ps;
	return 0;
}