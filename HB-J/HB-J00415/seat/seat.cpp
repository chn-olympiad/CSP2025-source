#include<bits/stdc++.h>
using namespace std;
int n,m,z,wei;
int ansn,ansm;
int a[105];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}z=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		if(z==a[i]){
			wei=i;
			break;
		}
	}ansm=(wei-1)/n+1;
	if(ansm%2==1) ansn=wei-n*(ansm-1);
	else ansn=m-(wei-n*(ansm-1))+1;
	cout<<ansm<<' '<<ansn;
	
	
	return 0;
}

