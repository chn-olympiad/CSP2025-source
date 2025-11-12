#include<bits/stdc++.h>
using namespace std;
int m,n,mapm[105],xk,bh,mk,ck;
bool cmp(int x,int y) {return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int jkkj=m*n;
	for(int i=1;i<=jkkj;i++){
		cin>>mapm[i];
	}
	xk=mapm[1];
	sort(mapm+1,mapm+jkkj+1,cmp);
	for(int i=1;i<=jkkj;i++){
		if(mapm[i]==xk){
			bh=i;
			break;
		}
	}
	ck=(bh+n-1)/n;
	mk=bh-n*(ck-1);
	if(ck%2!=0){cout<<ck<<" "<<mk;}
	else{cout<<ck<<" "<<m-mk;}
	return 0;
}
