#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],r;
int pm;

bool cmp(int a,int b){
	return a>b;
} 
 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			pm=i;
			break;
		}
	}
	int hs=ceil(pm*1.0/m);
	cout<<hs<<" ";
	if(hs%2==0){
		if(pm%m==0) cout<<1<<"\n";
		else cout<<m-pm%m+1<<"\n";
	}
	else{
		if(pm%m==0) cout<<m<<"\n";
		else cout<<pm%m<<"\n";
	}
	return 0;
}
