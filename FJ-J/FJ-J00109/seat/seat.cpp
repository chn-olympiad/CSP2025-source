#include<bits/stdc++.h>
using namespace std;

int sc[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,r_i;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
		if(i==1) r=sc[i];
	}
	sort(sc+1,sc+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sc[i]==r){
			r_i=i;
			break;
		}
	}
	int h=(r_i+n-1)/n;
	int l;
	if(h%2==1){
		if(r_i%n==0) l=n;
		else l=r_i%n;
	}else{
		if(r_i%n==0) l=(n-(r_i%n)+1)%n;
		else l=n-(r_i%n)+1;
	}
	cout<<h<<' '<<l;
	return 0;
}
