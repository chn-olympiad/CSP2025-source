#include <bits/stdc++.h>
using namespace std;
typedef long long L;
const L N=1e5+10;
L a[N];
bool cmp(L x,L y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	L n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n+1,cmp);
	int l=1,h=1,f=0;
	for(int i=1;i<=m*n;i++){
		if(!f){
			if(h==n) l++,f=1;
			else h++;
		}
		else{
			if(h==1) l++,f=0;
			else h--;
		}
		if(a[i]==r){
			cout<<h<<' '<<l;
			return 0;
		}
	}
	return 0;
}
