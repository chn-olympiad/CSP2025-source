#include <bits/stdc++.h>
using namespace std;
const int maxn=1003;
int a[maxn],n,m;
bool cmp(int q,int p){
	return q>p;
}
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int rl;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rl=a[1];
	sort(a+1,a+1+n*m,cmp);
	int r;
	for(r=1;r<=n*m;r++){
		if(a[r]==rl)break;
	}
	if(r==1)cout<<1<<" ";
	else cout<<((r-1)/n)+1<<" ";
	
	if(r==1)cout<<1;
	else if( (((r-1)/n)+1) % 2 == 0 ){
		cout<< n-(r-n*((r-1)/n))+1 ;
	}else{
		cout<< r-n*((r-1)/n);
	}
	return 0;
}
