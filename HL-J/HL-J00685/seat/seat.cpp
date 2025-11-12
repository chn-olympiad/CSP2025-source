#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[N],k,p,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*n;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			p=i;
			break;
		}
	}
	h=n;
	l=m;
	while(p!=0){
		
	}
	cout<<m<<' '<<n;
	return 0;
}
